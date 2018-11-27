/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vproc_q_tui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:11:03 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 22:52:29 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_vproc		*exec_vproc2(t_corewar *core, t_vproc *proc)
{
	t_vproc			*ret;

	if (core->dump > -1 && core->max_cycle == core->dump)
	{
		dump_mem(core);
		return (NULL);
	}
	proc = core->proc_q;
	ret = proc;
	while (proc)
	{
		exec_vproc(core, proc);
		proc = proc->next;
	}
	core->cycle++;
	core->max_cycle++;
	update_tui_cycle(core);
	if (core->pause == 1)
	{
		togle_exec_stat(core);
		core->pause = 0;
	}
	set_delay(core);
	return (ret);
}

static void			exec_vproc3(t_corewar *core)
{
	show_winner(core);
	while (1)
	{
		if (wgetch(core->inf_win) != ERR)
			return ;
	}
	return ;
}

void				exec_vproc_q_tui(t_corewar *core)
{
	t_vproc			*proc;
	int				c;

	if (!core || core->max_warr == 0)
		return ;
	c = 0;
	proc = NULL;
	init_vproc_q(core, core->proc_q);
	while (1)
	{
		if ((c = wgetch(core->inf_win)) != ERR)
			manage_input(core, c);
		if (core->exec_stat == STAT_PLAY)
		{
			if (check_delay(core) == SUCCESS)
			{
				if (core->cycle >= core->cycle_to_die)
					if (cycle_to_die_check(core) == ERROR)
						break ;
				if ((proc = exec_vproc2(core, proc)) == NULL)
					return ;
			}
		}
	}
	exec_vproc3(core);
}
