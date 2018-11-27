/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vproc_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:09:51 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 22:32:36 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void static inline	ext_exec_vproc_q(t_corewar *core, t_vproc **proc)
{
	exec_vproc(core, *proc);
	*proc = (*proc)->next;
}

void				exec_vproc_q(t_corewar *core)
{
	t_vproc	*proc;
	int		c;

	c = 0;
	proc = NULL;
	if (!core || core->max_warr == 0)
		return ;
	init_vproc_q(core, core->proc_q);
	while (1)
	{
		if (core->cycle >= core->cycle_to_die)
			if (cycle_to_die_check(core) == ERROR)
				break ;
		if (core->dump > -1 && core->max_cycle == core->dump)
		{
			dump_mem(core);
			return ;
		}
		proc = core->proc_q;
		while (proc)
			ext_exec_vproc_q(core, &proc);
		core->cycle++;
		core->max_cycle++;
	}
	show_winner(core);
}
