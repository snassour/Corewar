/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   togle_exec_stat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:01:05 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:01:44 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					togle_exec_stat(t_corewar *core)
{
	wclear(core->tui.stat);
	wattron(core->tui.stat, COLOR_PAIR(1) | A_BOLD);
	if (core->exec_stat == STAT_PLAY)
	{
		core->exec_stat = STAT_PAUSE;
		mvwprintw(core->tui.stat, 1, 2, "%s", (core->exec_stat == STAT_PAUSE)
				? "Play" : "Pause");
	}
	else
	{
		core->exec_stat = STAT_PLAY;
		mvwprintw(core->tui.stat, 1, 2, "%s", (core->exec_stat == STAT_PAUSE)
				? "Play" : "Pause");
	}
	wattroff(core->tui.stat, COLOR_PAIR(1) | A_BOLD);
	box(core->tui.stat, 0, 0);
	wrefresh(core->tui.stat);
	return (core->exec_stat);
}
