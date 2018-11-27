/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:04:54 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 22:27:01 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void static inline	delete_proc_ext(t_corewar *core, t_vproc *proc,
		t_vproc **next, t_vproc **prev)
{
	if ((core->flag & FLAG_T) != 0)
	{
		if (core->proc_list_pos == proc->id)
			core->proc_list_pos = -1;
		tui_write_mem_tog(proc->warr, proc->reg[REG_PC], 1);
	}
	if (proc->prev == NULL)
	{
		core->proc_q = *next;
		if (*next)
			(*next)->prev = NULL;
	}
	else
	{
		(*prev)->next = *next;
		if (*next)
			(*next)->prev = *prev;
	}
}

void				delete_proc(t_corewar *core, t_vproc *proc)
{
	t_vproc		*prev;
	t_vproc		*next;

	if (!core || !proc)
		return ;
	next = proc->next;
	prev = proc->prev;
	delete_proc_ext(core, proc, &next, &prev);
	free(proc);
	core->proc_q_len--;
	if (core->proc_q_len == 0)
		core->proc_q = NULL;
}
