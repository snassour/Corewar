/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:04 by snassour          #+#    #+#             */
/*   Updated: 2018/10/21 18:43:59 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_checklabelarg(char *line, int start, t_asm *data, int nb_arg)
{
	int		i;
	char	c;

	i = 0;
	while (line[i + start] && ft_strchr(LABEL_CHARS, line[i + start]))
		++i;
	if (i != 0 && (line[i + start] == SEPARATOR_CHAR || line[i + start] == '\t'
		|| line[i + start] == ' ' || line[i + start] == '\0'))
	{
		data->label_in_arg[nb_arg] = LABEL_SET;
		c = line[i + start];
		line[i + start] = '\0';
		data->labels[nb_arg] = NULL;
		data->labels[nb_arg] = ft_strdup(line + start);
		line[i + start] = c;
		data->get_label = YES;
		if (asm_lablist(data, data->labels[nb_arg]) == 1)
			data->arg[nb_arg] = asm_bigendian(data->pc_label - data->pc, 4);
		if (data->op_tab[data->cmd].index == 1)
			data->arg_len[nb_arg] = 2;
		return (i);
	}
	return (-1);
}

int		asm_checkdir(char *line, int beg, t_asm *d, int n_arg)
{
	int		i;
	int		nb;
	char	c;

	if ((line[beg] != DIRECT_CHAR) || !(d->op_tab[d->cmd].arg[n_arg] & T_DIR))
		return (-1);
	d->arg_type[n_arg] = 2;
	i = 1;
	d->arg_len[n_arg] = d->op_tab[d->cmd].index == 1 ? 2 : 4;
	if ((line + beg)[i] == LABEL_CHAR)
	{
		i = asm_checklabelarg(line, beg + 1 + i, d, n_arg);
		return (i == -1 ? i : i + 2);
	}
	i = ((line + beg)[i] == '-' ? 2 : 1);
	while ((line + beg)[i] <= '9' && (line + beg)[i] >= '0')
		i++;
	if (i == 1 || ((line + beg)[1] == '-' && i == 2))
		return (-1);
	c = (line + beg)[i];
	(line + beg)[i] = '\0';
	nb = asm_bigendian(ft_atoi((line + beg) + 1), 4);
	(line + beg)[i] = c;
	d->arg[n_arg] = nb;
	return (i);
}

int		asm_checkind(char *line, int begin, t_asm *data, int nb_arg)
{
	int		i;
	char	c;
	int		nb;

	i = 0;
	if ((data->op_tab[data->cmd].arg[nb_arg] & T_IND) == 0)
		return (-1);
	data->arg_type[nb_arg] = 3;
	data->arg_len[nb_arg] = 2;
	if ((line + begin)[0] == LABEL_CHAR)
	{
		i = asm_checklabelarg(line, begin + 1, data, nb_arg);
		return (i == -1 ? -1 : i + 1);
	}
	i = ((line + begin)[i] == '-' ? 1 : 0);
	while ((line + begin)[i] <= '9' && (line + begin)[i] >= '0')
		i++;
	if (i == 0 || ((line + begin)[0] == '-' && i == 1))
		return (-1);
	c = (line + begin)[i];
	(line + begin)[i] = '\0';
	nb = asm_bigendian(ft_atoi((line + begin)), 4);
	(line + begin)[i] = c;
	data->arg[nb_arg] = nb;
	return (i);
}

int		asm_checkreg(char *line, int begin, int nb_arg, t_asm *data)
{
	int		i;
	int		nb;
	char	c;

	if (*(line + begin) != 'r')
		return (-1);
	i = 1;
	if ((data->op_tab[data->cmd].arg[nb_arg] & T_REG) == 0)
		return (-1);
	while (line[i + begin] && line[i + begin] <= '9' && line[begin + i] >= '0')
		i++;
	if (i == 1 || i > 3)
		return (-1);
	c = (line + begin)[i];
	(line + begin)[i] = '\0';
	nb = ft_atoi((line + begin) + 1);
	(line + begin)[i] = c;
	if (nb > REG_NUMBER || nb < 1)
		return (-1);
	data->arg[nb_arg] = nb;
	data->arg_type[nb_arg] = 1;
	data->arg_len[nb_arg] = 1;
	return ((nb > REG_NUMBER || nb < 1) ? -1 : i);
}
