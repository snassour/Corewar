/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:53 by snassour          #+#    #+#             */
/*   Updated: 2018/10/21 18:34:13 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_check_type_arg(char **line, int j, int i, t_asm *data)
{
	int		err;
	int		conv;

	err = -1;
	conv = data->cmd;
	data->error_type = (data->op_tab[conv].arg[i] & T_REG) * INV_TYPE_R;
	data->error_type += ((data->op_tab[conv].arg[i] & T_DIR) / 2) * INV_TYPE_D;
	data->error_type += ((data->op_tab[conv].arg[i] & T_IND) / 4) * INV_TYPE_I;
	if ((*line)[j] == 'r' && (err = asm_checkreg(*line, j, i, data)) < 0)
		return (asm_parse_file_error(data, line, NULL));
	else if ((*line)[j] == DIRECT_CHAR)
	{
		if ((err = asm_checkdir(*line, j, data, i)) < 0)
			return (asm_parse_file_error(data, line, NULL));
	}
	else if (((*line)[j] == LABEL_CHAR
	|| ((*line)[j] <= '9' && (*line)[j] >= '0') || (*line)[j] == '-'))
	{
		if ((err = asm_checkind(*line, j, data, i)) < 0)
			return (asm_parse_file_error(data, line, NULL));
	}
	else if (err == -1)
		return (asm_parse_file_error(data, line, NULL));
	return (err);
}

int		asm_checkargument(char *line, int j, t_asm *d, int cv)
{
	int err;
	int	sep_c;

	err = 0;
	d->curr_arg = 0;
	sep_c = 0;
	while (line[j] && d->curr_arg < d->op_tab[cv].n_arg && err >= 0)
	{
		d->get_label = 0;
		j += asm_blank(line, j);
		d->error_type = INVALID_ARG_NUM;
		j = (line[j] == SEPARATOR_CHAR ? ((j + 1) + (0 * ++sep_c)) : j);
		if ((d->curr_arg == 0 && sep_c == 1) || (sep_c >= d->op_tab[cv].n_arg))
			return (asm_parse_file_error(d, &line, NULL));
		j += asm_blank(line, j);
		if ((err = asm_check_type_arg(&line, j, d->curr_arg, d)) == -1)
			return (-1);
		j += err;
		j += asm_blank(line, j);
		d->curr_arg++;
	}
	d->error_type = (line[j] != '\0' ? INVALID_ARG_NUM : d->error_type);
	if (sep_c != d->op_tab[cv].n_arg - 1 || line[j] != '\0')
		return (asm_parse_file_error(d, &line, NULL));
	return (1);
}

int		asm_checkcmd(char *l, int b, t_asm *d)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	d->set_label = 0;
	while ((l + b)[j] <= 'z' && (l + b)[j] >= 'a')
		++j;
	while (++i < 16)
		if (!ft_strncmp(l + b, d->op_tab[i].cmd, asm_max(d->op_tab[i].len, j)))
			break ;
	d->error_type = UNKNOWN_FUNCTION;
	if (i == 16)
		return (asm_parse_file_error(d, &l, NULL));
	j += asm_blank(l, b + d->op_tab[i].len);
	d->error_type = INVALID_ARGUMENT;
	if ((l + b)[j] == '\0')
		return (asm_parse_file_error(d, &l, NULL));
	d->cmd = i;
	d->nb_arg = d->op_tab[i].n_arg;
	if (asm_checkargument(l, b + j, d, i) == -1)
		return (-1);
	if (asm_create_corlist(d) == -1)
		return (-1);
	return (1);
}

char	*asm_removecomment(char *line)
{
	char	*loc;

	if ((loc = ft_strchr(line, COMMENT_CHAR)))
		*loc = '\0';
	if ((loc = ft_strchr(line, END_COMMENT_CHAR)))
		*loc = '\0';
	loc = NULL;
	loc = ft_strtrim(line);
	return (loc);
}
