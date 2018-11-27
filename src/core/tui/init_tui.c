/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:13:35 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:48:06 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				set_proc_reg(WINDOW **reg)
{
	mvwprintw((reg[REG_PC]), 1, 1, "%*s", 4, "PC");
	mvwprintw((reg[REG_R1]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R2]), 1, 1, "%*s", 4, "R2");
	mvwprintw((reg[REG_R3]), 1, 1, "%*s", 4, "R3");
	mvwprintw((reg[REG_R4]), 1, 1, "%*s", 4, "R4");
	mvwprintw((reg[REG_R5]), 1, 1, "%*s", 4, "R5");
	mvwprintw((reg[REG_R6]), 1, 1, "%*s", 4, "R6");
	mvwprintw((reg[REG_R7]), 1, 1, "%*s", 4, "R7");
	mvwprintw((reg[REG_R8]), 1, 1, "%*s", 4, "R8");
	mvwprintw((reg[REG_R9]), 1, 1, "%*s", 4, "R9");
	mvwprintw((reg[REG_R10]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R11]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R12]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R13]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R14]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R15]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_R16]), 1, 1, "%*s", 4, "R1");
	mvwprintw((reg[REG_CF]), 1, 1, "%*s", 4, "CF");
}

char				*p_name(uint8_t *name)
{
	static char		str[70];
	int				i;

	if (!name)
		return (NULL);
	i = 0;
	ft_memset(str, 0, 70);
	while (name[i] && i < 70 && i < VM_PROG_NAME_LENGTH)
	{
		if (ft_isprint(name[i]))
			str[i] = name[i];
		else
			str[i] = '.';
		i++;
	}
	return (str);
}

int					init_tui(t_corewar *core)
{
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	curs_set(0);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	if (create_windows(core) == ERROR)
		return (ERROR);
	pair_color_start();
	init_mem_win(core);
	set_button(core);
	set_player_number(core);
	set_player_name(core);
	set_general_core_info(core);
	set_proc_head(core);
	set_proc_reg(core->tui.reg_bf_name);
	set_proc_reg(core->tui.reg_af_name);
	keypad(core->inf_win, TRUE);
	nodelay(core->inf_win, TRUE);
	set_window_box(core);
	refresh_windows(core);
	return (SUCCESS);
}
