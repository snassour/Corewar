/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 00:05:08 by snassour          #+#    #+#             */
/*   Updated: 2018/10/04 00:05:12 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_set_corlist(t_asm *data, t_clst **new)
{
	int		i;

	(*new)->pc = data->pc;
	(*new)->opcode = data->cmd;
	(*new)->nb_arg = 1 + data->op_tab[data->cmd].ocp;
	(*new)->ocparam = 0;
	i = -1;
	while (++i < 3)
	{
		(*new)->arg[i] = data->arg[i];
		(*new)->label_in_arg[i] = data->label_in_arg[i];
		if (data->label_in_arg[i] && data->labels[i])
			(*new)->labels[i] = ft_strdup(data->labels[i]);
		else
			(*new)->labels[i] = NULL;
		ft_strdel(&(data->labels[i]));
		(*new)->arg_type[i] = data->arg_type[i];
		(*new)->arg_len[i] = data->arg_len[i];
		(*new)->ocparam |= data->arg_type[i];
		(*new)->ocparam <<= 2;
		(*new)->nb_arg += data->arg_len[i];
	}
	(*new)->ocparam *= (data->op_tab[data->cmd].ocp);
	data->pc += (*new)->nb_arg;
}

int		asm_create_corlist(t_asm *data)
{
	t_clst	*new;
	t_clst	*tmp;

	new = NULL;
	data->error_type = MFAIL;
	if (!(new = (t_clst *)malloc(sizeof(t_clst))))
		return (asm_parse_file_error(data, NULL, NULL));
	new->arg_len[0] = 0;
	new->arg_len[1] = 0;
	new->arg_len[2] = 0;
	asm_set_corlist(data, &new);
	new->next = NULL;
	if (data->begin == NULL)
	{
		data->begin = new;
		data->begin->next = NULL;
		return (1);
	}
	tmp = data->begin;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	tmp->next->next = NULL;
	return (1);
}

void	asm_destroy_corlist(t_asm *data)
{
	t_clst	*lst;
	t_clst	*tmp;

	lst = data->begin;
	while (lst && lst->next)
	{
		ft_strdel(&(lst->labels[0]));
		ft_strdel(&(lst->labels[1]));
		ft_strdel(&(lst->labels[2]));
		tmp = lst->next;
		free(lst);
		lst = NULL;
		lst = tmp;
	}
	ft_strdel(&(lst->labels[0]));
	ft_strdel(&(lst->labels[1]));
	ft_strdel(&(lst->labels[2]));
	free(lst);
	lst = NULL;
	data->begin = NULL;
}
