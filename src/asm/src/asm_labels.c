/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_labels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 03:25:05 by snassour          #+#    #+#             */
/*   Updated: 2018/10/04 03:25:08 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_replace_labels(t_asm *d)
{
	t_clst	*l_cmd;
	int		i;

	d->set_label = NO;
	d->get_label = YES;
	l_cmd = d->begin;
	d->error_type = UNDEFINED_LABEL;
	ft_strdel(&(d->str));
	while (l_cmd)
	{
		i = -1;
		while (++i < 3)
			if (l_cmd->label_in_arg[i])
			{
				if (l_cmd->labels[i])
					if (asm_set_lablist(d, l_cmd->labels[i], 1) == -1)
					{
						d->str = ft_strdup(l_cmd->labels[i]);
						return (asm_parse_file_error(d, NULL, NULL));
					}
				l_cmd->arg[i] = asm_bigendian(d->pc_label - l_cmd->pc, 4);
			}
		l_cmd = l_cmd->next;
	}
	return (1);
}

int		asm_check_label_used(t_asm *data)
{
	t_lbl	*tmp;

	tmp = data->lablist;
	while (tmp)
	{
		if (tmp->set_label == NO)
		{
			data->line_error = tmp->line_label;
			ft_strdel(&(data)->str);
			data->str = ft_strdup(tmp->name);
			data->error_type = INVALID_LABEL;
			return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int		asm_set_lablist(t_asm *d, char *s, int er)
{
	t_lbl	*tmp;

	tmp = d->lablist;
	while (tmp && tmp->next && s && ft_strcmp(tmp->name, s))
		tmp = tmp->next;
	if (tmp && s && ft_strcmp(tmp->name, s) && tmp->next == NULL)
		return (NO_LABEL_NAME);
	if ((s && ft_strcmp(tmp->name, s)) || !s)
		return (NO_LABEL_NAME);
	if (d->set_label == YES)
	{
		tmp->pc = (tmp->set_label == 0 ? d->pc : tmp->pc);
		tmp->set_label = YES;
		return (1);
	}
	if (d->get_label == YES)
	{
		d->line_error = (er == 1 ? tmp->line_label : d->line_error);
		d->pc_label = (tmp->set_label == YES ? tmp->pc : d->pc_label);
		if (tmp->set_label == YES)
			return (1);
		d->set_label = LABEL_NOTSET;
		return (-1);
	}
	return (NO_LABEL_NAME);
}

int		asm_lablist(t_asm *data, char *s)
{
	t_lbl	*new;
	int		i;

	new = NULL;
	if (s == NULL)
		return (-1);
	i = 0;
	data->error_type = INVALID_LABEL;
	if (data->lablist != NULL)
		i = asm_set_lablist(data, s, 0);
	if (i == 1 || i == -1)
		return (i);
	data->error_type = MFAIL;
	if (!(new = (t_lbl *)malloc(sizeof(t_lbl))))
		return (asm_parse_file_error(data, NULL, NULL));
	if (!(new->name = ft_strdup(s)))
		return (asm_parse_file_error(data, NULL, NULL));
	new->line_label = data->line_error + 1;
	new->set_label = data->set_label;
	new->pc = data->set_label * (data->pc);
	new->next = data->lablist;
	data->lablist = new;
	return (1);
}

void	asm_destroy_lablist(t_asm *data)
{
	t_lbl	*lst;
	t_lbl	*tmp;

	lst = data->lablist;
	while (lst && lst->next)
	{
		tmp = lst->next;
		ft_strdel(&(lst->name));
		free(lst);
		lst = NULL;
		lst = tmp;
	}
	ft_strdel(&(lst->name));
	free(lst);
	lst = NULL;
	data->begin = NULL;
}
