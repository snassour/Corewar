/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:00:34 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:00:54 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				tui_add_list(t_corewar *core)
{
	int				i;
	t_vproc			*proc;

	if (!core || !(core->proc_q))
		return ;
	i = 0;
	proc = core->proc_q;
	if (core->proc_q_len >= MAX_PROC_IN_LIST)
		return ;
	ft_memset(core->proc_list, 0, MAX_PROC_IN_LIST);
	while (i < MAX_PROC_IN_LIST && proc)
	{
		core->proc_list[i] = proc;
		proc = proc->next;
		i++;
	}
	core->proc_list_len++;
	core->proc_list_pos++;
	update_proc_list(core);
}
