/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:47:25 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 20:03:29 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void static inline		cycle_to_die_check_ext(t_corewar *core, t_vproc *proc,
		t_vproc *copy)
{
	while (proc)
	{
		if (proc->live == 0)
		{
			copy = proc->next;
			delete_proc(core, proc);
			proc = copy;
			continue ;
		}
		else
			proc->live = 0;
		proc = proc->next;
	}
}

int						cycle_to_die_check(t_corewar *core)
{
	t_vproc				*proc;
	t_vproc				*copy;

	copy = NULL;
	if (!core || !(core->proc_q) || core->cycle_to_die <= 0 \
			|| core->proc_q_len <= 0)
		return (ERROR);
	proc = core->proc_q;
	cycle_to_die_check_ext(core, proc, copy);
	if (!(core->proc_q))
		return (ERROR);
	if (core->live_count >= VM_NBR_LIVE)
	{
		core->cycle_to_die -= VM_CYCLE_DELTA;
		core->live_count = 0;
		update_cycle_to_die(core);
		update_live(core);
	}
	core->cycle = 0;
	return (SUCCESS);
}
