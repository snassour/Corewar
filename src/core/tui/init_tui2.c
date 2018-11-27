/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:31:30 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:11:17 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				pair_color_start(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
}

void				init_mem_win(t_corewar *core)
{
	int				i;
	int				sf;
	int				new_line;

	i = 0;
	sf = 0;
	new_line = 1;
	wattron(core->mem_win, COLOR_PAIR(1) | A_DIM);
	wmove(core->mem_win, 1, 2);
	while (i < VM_MEM_SIZE)
	{
		wprintw(core->mem_win, "%02hu", core->memory[i]);
		sf++;
		if ((i + 1) < VM_MEM_SIZE)
			wprintw(core->mem_win, " ");
		if (sf == 64)
		{
			wprintw(core->mem_win, "\n");
			new_line++;
			wmove(core->mem_win, new_line, 2);
			sf = 0;
		}
		i++;
	}
	wattroff(core->mem_win, COLOR_PAIR(1) | A_DIM);
}

void				init_box(t_corewar *core)
{
	core->tui.reg_bf_box = newwin(TUI_REG_BF_BOX_HEIGHT, TUI_REG_BF_BOX_WIDTH,
			TUI_REG_BF_BOX_ORGN_Y, TUI_REG_BF_BOX_ORGN_X);
	core->tui.reg_af_box = newwin(TUI_REG_AF_BOX_HEIGHT, TUI_REG_AF_BOX_WIDTH,
			TUI_REG_AF_BOX_ORGN_Y, TUI_REG_AF_BOX_ORGN_X);
}

int					check_data(t_corewar *core)
{
	int				i;

	i = -1;
	while (++i < 18)
		if (!core->tui.reg_af[i] || !core->tui.reg_af_name[i] ||
				!core->tui.reg_bf[i] || !core->tui.reg_bf_name[i])
			return (ERROR);
	i = -1;
	while (++i < 9)
		if (!(core->tui.process[i]))
			return (ERROR);
	i = -1;
	while (++i < 4)
		if (!(core->tui.p_name[i]) || !(core->tui.p_num[i]))
			return (ERROR);
	if (!(core->mem_win) || !(core->inf_win) || !(core->tui.max_proc) ||
		!(core->tui.stat) || !(core->tui.next) || !(core->tui.speed) ||
		!(core->tui.high) || !(core->tui.low) || !(core->tui.cycle) ||
		!(core->tui.proc_box) || !(core->tui.cycle_val) || !(core->tui.live) ||
		!(core->tui.cycle_to_die) || !(core->tui.cycle_to_die_val) ||
		!(core->tui.max_proc_val) || !(core->tui.live_val) ||
		!(core->tui.proc_head) || !(core->tui.proc_list) ||
		!(core->tui.reg_bf_box) || !(core->tui.reg_af_box))
		return (ERROR);
	return (SUCCESS);
}
