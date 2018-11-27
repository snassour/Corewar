/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui_winbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:31:01 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 15:40:45 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static void			init_winbox2(t_corewar *core)
{
	box(core->tui.proc_list, 0, 0);
	box(core->tui.proc_box, 0, 0);
	box(core->tui.reg_bf_box, 0, 0);
	box(core->tui.reg_af_box, 0, 0);
}

void				init_winbox1(t_corewar *core)
{
	box(core->mem_win, 0, 0);
	box(core->inf_win, 0, 0);
	box(core->tui.stat, 0, 0);
	box(core->tui.next, 0, 0);
	box(core->tui.speed, 0, 0);
	box(core->tui.high, 0, 0);
	box(core->tui.low, 0, 0);
	box(core->tui.p_num[0], 0, 0);
	box(core->tui.p_num[1], 0, 0);
	box(core->tui.p_num[2], 0, 0);
	box(core->tui.p_num[3], 0, 0);
	box(core->tui.p_name[0], 0, 0);
	box(core->tui.p_name[1], 0, 0);
	box(core->tui.p_name[2], 0, 0);
	box(core->tui.p_name[3], 0, 0);
	box(core->tui.cycle, 0, 0);
	box(core->tui.cycle_val, 0, 0);
	box(core->tui.cycle_to_die, 0, 0);
	box(core->tui.cycle_to_die_val, 0, 0);
	box(core->tui.live, 0, 0);
	box(core->tui.live_val, 0, 0);
	box(core->tui.max_proc, 0, 0);
	box(core->tui.max_proc_val, 0, 0);
	box(core->tui.proc_head, 0, 0);
	init_winbox2(core);
}

void				set_window_box(t_corewar *core)
{
	int				i;

	init_winbox1(core);
	i = 0;
	while (i < VM_MAX_REG_NUMBER)
	{
		wattron(core->tui.reg_bf[i], COLOR_PAIR(1) | A_DIM);
		wattron(core->tui.reg_bf_name[i], COLOR_PAIR(1) | A_DIM);
		wattron(core->tui.reg_af[i], COLOR_PAIR(1) | A_DIM);
		wattron(core->tui.reg_af_name[i], COLOR_PAIR(1) | A_DIM);
		box(core->tui.reg_bf[i], 0, 0);
		box(core->tui.reg_bf_name[i], 0, 0);
		box(core->tui.reg_af_name[i], 0, 0);
		box(core->tui.reg_af[i], 0, 0);
		wattroff(core->tui.reg_bf[i], COLOR_PAIR(1) | A_DIM);
		wattroff(core->tui.reg_af_name[i], COLOR_PAIR(1) | A_DIM);
		wattroff(core->tui.reg_af[i], COLOR_PAIR(1) | A_DIM);
		wattroff(core->tui.reg_af[i], COLOR_PAIR(1) | A_DIM);
		i++;
	}
}

void				refresh_win1(t_corewar *core)
{
	wrefresh(core->mem_win);
	wrefresh(core->inf_win);
	wrefresh(core->tui.stat);
	wrefresh(core->tui.next);
	wrefresh(core->tui.speed);
	wrefresh(core->tui.high);
	wrefresh(core->tui.low);
	wrefresh(core->tui.p_num[0]);
	if (core->max_warr >= 2)
		wrefresh(core->tui.p_num[1]);
	if (core->max_warr >= 3)
		wrefresh(core->tui.p_num[2]);
	if (core->max_warr >= 4)
		wrefresh(core->tui.p_num[3]);
	wrefresh(core->tui.p_name[0]);
	if (core->max_warr >= 2)
		wrefresh(core->tui.p_name[1]);
	if (core->max_warr >= 3)
		wrefresh(core->tui.p_name[2]);
	if (core->max_warr >= 4)
		wrefresh(core->tui.p_name[3]);
	wrefresh(core->tui.cycle);
}

void				refresh_windows(t_corewar *core)
{
	int				i;

	refresh_win1(core);
	wrefresh(core->tui.cycle_val);
	wrefresh(core->tui.cycle_to_die);
	wrefresh(core->tui.cycle_to_die_val);
	wrefresh(core->tui.live);
	wrefresh(core->tui.live_val);
	wrefresh(core->tui.max_proc);
	wrefresh(core->tui.max_proc_val);
	wrefresh(core->tui.proc_list);
	wrefresh(core->tui.proc_head);
	wrefresh(core->tui.proc_box);
	wrefresh(core->tui.reg_bf_box);
	wrefresh(core->tui.reg_af_box);
	i = 0;
	while (i < VM_MAX_REG_NUMBER)
	{
		wrefresh(core->tui.reg_bf_name[i]);
		wrefresh(core->tui.reg_bf[i]);
		wrefresh(core->tui.reg_af_name[i]);
		wrefresh(core->tui.reg_af[i++]);
	}
}
