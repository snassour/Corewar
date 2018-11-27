/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:29:36 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:48:50 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void			init_core2(t_corewar *core)
{
	core->tui.cycle = newwin(TUI_CYCLE_HEIGHT, TUI_CYCLE_WIDTH,
			TUI_CYCLE_ORGN_Y, TUI_CYCLE_ORGN_X);
	core->tui.cycle_val = newwin(TUI_CYCLE_VAL_HEIGHT, TUI_CYCLE_VAL_WIDTH,
			TUI_CYCLE_VAL_ORGN_Y, TUI_CYCLE_VAL_ORGN_X);
	core->tui.cycle_to_die = newwin(TUI_CYCLE_TO_DIE_HEIGHT,
			TUI_CYCLE_TO_DIE_WIDTH, TUI_CYCLE_TO_DIE_ORGN_Y,
			TUI_CYCLE_TO_DIE_ORGN_X);
	core->tui.cycle_to_die_val = newwin(TUI_CYCLE_TO_DIE_VAL_HEIGHT,
			TUI_CYCLE_TO_DIE_VAL_WIDTH, TUI_CYCLE_TO_DIE_VAL_ORGN_Y,
			TUI_CYCLE_TO_DIE_VAL_ORGN_X);
	core->tui.live = newwin(TUI_LIVE_HEIGHT, TUI_LIVE_WIDTH, TUI_LIVE_ORGN_Y,
			TUI_LIVE_ORGN_X);
	core->tui.live_val = newwin(TUI_LIVE_VAL_HEIGHT, TUI_LIVE_VAL_WIDTH,
			TUI_LIVE_VAL_ORGN_Y, TUI_LIVE_VAL_ORGN_X);
	core->tui.max_proc = newwin(TUI_MAX_PROC_HEIGHT,
			TUI_MAX_PROC_WIDTH, TUI_MAX_PROC_ORGN_Y, TUI_MAX_PROC_ORGN_X);
	core->tui.max_proc_val = newwin(TUI_MAX_PROC_VAL_HEIGHT,
			TUI_MAX_PROC_VAL_WIDTH, TUI_MAX_PROC_VAL_ORGN_Y,
			TUI_MAX_PROC_VAL_ORGN_X);
	core->tui.proc_head = newwin(TUI_PROC_HEAD_HEIGHT, TUI_PROC_HEAD_WIDTH,
			TUI_PROC_HEAD_ORGN_Y, TUI_PROC_HEAD_ORGN_X);
	core->tui.proc_list = newwin(TUI_PROC_LIST_HEIGHT, TUI_PROC_LIST_WIDTH,
			TUI_PROC_LIST_ORGN_Y, TUI_PROC_LIST_ORGN_X);
}

void			init_core1(t_corewar *core)
{
	core->mem_win = newwin(MEM_WIN_HEIGHT, MEM_WIN_WIDTH, 0, 0);
	core->inf_win = newwin(INF_WIN_HEIGHT, INF_WIN_WIDTH, 0, MEM_WIN_WIDTH);
	core->tui.stat = newwin(TUI_STAT_HEIGHT, TUI_STAT_WIDTH, TUI_STAT_ORGN_Y,
			TUI_STAT_ORGN_X);
	core->tui.next = newwin(TUI_NEXT_HEIGHT, TUI_NEXT_WIDTH, TUI_NEXT_ORGN_Y,
			TUI_NEXT_ORGN_X);
	core->tui.speed = newwin(TUI_SPEED_HEIGHT, TUI_SPEED_WIDTH,
			TUI_SPEED_ORGN_Y, TUI_SPEED_ORGN_X);
	core->tui.high = newwin(TUI_HIGH_HEIGHT, TUI_HIGH_WIDTH, TUI_HIGH_ORGN_Y,
			TUI_HIGH_ORGN_X);
	core->tui.low = newwin(TUI_LOW_HEIGHT, TUI_LOW_WIDTH, TUI_LOW_ORGN_Y,
			TUI_LOW_ORGN_X);
}
