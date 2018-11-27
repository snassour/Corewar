/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tui_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:50:28 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 19:39:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				update_proc_reg_info(t_corewar *core)
{
	if (!core || (core->proc_list_pos < 0) || core->proc_list_pos > 9 ||
			core->proc_list_pos >= core->proc_list_len)
		return ;
	update_reg_val(core->tui.reg_bf,
			core->proc_list[core->proc_list_pos]->reg_bf);
	update_reg_val(core->tui.reg_af, core->proc_list[core->proc_list_pos]->reg);
}

void				update_cycle_to_die(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	mvwprintw(core->tui.cycle_to_die_val, 1, 1, "%27c\n", ' ');
	mvwprintw(core->tui.cycle_to_die_val, 1, 1, "%27d\n", core->cycle_to_die);
	box(core->tui.cycle_to_die_val, 0, 0);
	wrefresh(core->tui.cycle_to_die_val);
}

void				update_live(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	mvwprintw(core->tui.live_val, 1, 1, "%27c\n", ' ');
	mvwprintw(core->tui.live_val, 1, 1, "%27d\n", core->live_count);
	box(core->tui.live_val, 0, 0);
	wrefresh(core->tui.live_val);
}

void				update_max_process(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	mvwprintw(core->tui.max_proc_val, 1, 1, "%27c\n", ' ');
	mvwprintw(core->tui.max_proc_val, 1, 1, "%27d\n", core->proc_q_len);
	box(core->tui.max_proc_val, 0, 0);
	wrefresh(core->tui.max_proc_val);
}

void				update_tui_cycle(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	if (core->mem_change != 0)
	{
		wrefresh(core->mem_win);
		core->mem_change = 0;
	}
	update_cycle(core);
	update_max_process(core);
	update_proc_reg_info(core);
}
