/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:35:19 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:44:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				set_player_name(t_corewar *core)
{
	wattron(core->tui.p_name[0], COLOR_PAIR(2) | A_BOLD);
	wattron(core->tui.p_name[1], COLOR_PAIR(3) | A_BOLD);
	wattron(core->tui.p_name[2], COLOR_PAIR(4) | A_BOLD);
	wattron(core->tui.p_name[3], COLOR_PAIR(5) | A_BOLD);
	mvwprintw(core->tui.p_name[0], 1, 2, "%.49s", p_name(core->warr[0].name));
	mvwprintw(core->tui.p_name[1], 1, 2, "%.49s", p_name(core->warr[1].name));
	mvwprintw(core->tui.p_name[2], 1, 2, "%.49s", p_name(core->warr[2].name));
	mvwprintw(core->tui.p_name[3], 1, 2, "%.49s", p_name(core->warr[3].name));
	wattroff(core->tui.p_name[0], COLOR_PAIR(2) | A_BOLD);
	wattroff(core->tui.p_name[1], COLOR_PAIR(3) | A_BOLD);
	wattroff(core->tui.p_name[2], COLOR_PAIR(4) | A_BOLD);
	wattroff(core->tui.p_name[3], COLOR_PAIR(5) | A_BOLD);
}

void				set_general_core_info(t_corewar *core)
{
	mvwprintw(core->tui.cycle, 1, 2, "%16s", "Cycle");
	mvwprintw(core->tui.cycle_val, 1, 1, "%27d", core->cycle);
	mvwprintw(core->tui.cycle_to_die, 1, 2, "%20s", "Cycle To Die");
	mvwprintw(core->tui.cycle_to_die_val, 1, 1, "%27d", core->cycle_to_die);
	mvwprintw(core->tui.live, 1, 2, "%19s", "Live Calls");
	mvwprintw(core->tui.live_val, 1, 1, "%27d", core->live_count);
	mvwprintw(core->tui.max_proc, 1, 2, "%20s", "Max Processes");
	mvwprintw(core->tui.max_proc_val, 1, 1, "%27d", core->proc_q_len);
}

void				set_proc_head(t_corewar *core)
{
	mvwprintw(core->tui.proc_head, 1, 2, "%*s", 6, "ID");
}

void				set_button(t_corewar *core)
{
	wattron(core->tui.stat, COLOR_PAIR(1) | A_BOLD);
	wattron(core->tui.next, COLOR_PAIR(1) | A_BOLD);
	wattron(core->tui.speed, COLOR_PAIR(1) | A_BOLD);
	wattron(core->tui.high, COLOR_PAIR(1) | A_BOLD);
	wattron(core->tui.low, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(core->tui.stat, 1, 2, "%s", (core->exec_stat == STAT_PAUSE) ?
			"Play" : "Pause");
	mvwprintw(core->tui.next, 1, 2, "Next");
	mvwprintw(core->tui.speed, 1, 2, "%*d%%", TUI_SPEED_CHAR_WIDTH + (3 -
				ft_intlen(core->exec_speed)), core->exec_speed);
	mvwprintw(core->tui.high, 1, 2, "Up");
	mvwprintw(core->tui.low, 1, 2, "Down");
	wattroff(core->tui.stat, COLOR_PAIR(1) | A_BOLD);
	wattroff(core->tui.next, COLOR_PAIR(1) | A_BOLD);
	wattroff(core->tui.speed, COLOR_PAIR(1) | A_BOLD);
	wattroff(core->tui.high, COLOR_PAIR(1) | A_BOLD);
	wattroff(core->tui.low, COLOR_PAIR(1) | A_BOLD);
}

void				set_player_number(t_corewar *core)
{
	wattron(core->tui.p_num[0], COLOR_PAIR(2) | A_BOLD);
	wattron(core->tui.p_num[1], COLOR_PAIR(3) | A_BOLD);
	wattron(core->tui.p_num[2], COLOR_PAIR(4) | A_BOLD);
	wattron(core->tui.p_num[3], COLOR_PAIR(5) | A_BOLD);
	mvwprintw(core->tui.p_num[0], 1, 2, "%d", core->warr[0].warr_nb);
	mvwprintw(core->tui.p_num[1], 1, 2, "%d", core->warr[1].warr_nb);
	mvwprintw(core->tui.p_num[2], 1, 2, "%d", core->warr[2].warr_nb);
	mvwprintw(core->tui.p_num[3], 1, 2, "%d", core->warr[3].warr_nb);
	wattroff(core->tui.p_num[0], COLOR_PAIR(2) | A_BOLD);
	wattroff(core->tui.p_num[1], COLOR_PAIR(3) | A_BOLD);
	wattroff(core->tui.p_num[2], COLOR_PAIR(4) | A_BOLD);
	wattroff(core->tui.p_num[3], COLOR_PAIR(5) | A_BOLD);
}
