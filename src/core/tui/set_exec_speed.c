/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exec_speed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:01:51 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:02:51 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				set_exec_speed(t_corewar *core, int percent)
{
	if (percent <= 0)
		percent = 1;
	else if (percent > 100)
		percent = 100;
	core->exec_speed = percent;
	wattron(core->tui.speed, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(core->tui.speed, 1, 2, "%*c", 15, ' ');
	if (ft_intlen(core->exec_speed) == 1)
		mvwprintw(core->tui.speed, 1, 2, "%*d%%", TUI_SPEED_CHAR_WIDTH,
				core->exec_speed);
	if (ft_intlen(core->exec_speed) == 2)
		mvwprintw(core->tui.speed, 1, 2, "%*d%%", TUI_SPEED_CHAR_WIDTH,
				core->exec_speed);
	if (ft_intlen(core->exec_speed) == 3)
		mvwprintw(core->tui.speed, 1, 2, "%*d%%", TUI_SPEED_CHAR_WIDTH,
				core->exec_speed);
	wattroff(core->tui.speed, COLOR_PAIR(1) | A_BOLD);
	wrefresh(core->tui.speed);
}
