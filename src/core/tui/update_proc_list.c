/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_proc_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:55:30 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 19:40:19 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			update_proc_list2(t_corewar *core, int i)
{
	if (i == core->proc_list_pos)
		wattron(core->tui.process[i],
				COLOR_PAIR(core->proc_list[i]->warr->color_p) | A_BOLD);
	else
		wattron(core->tui.process[i], COLOR_PAIR(1) | A_DIM);
	box(core->tui.process[i], 0, 0);
	mvwprintw(core->tui.process[i], 1, 1, "%6d", core->proc_list[i]->id);
	if (i == core->proc_list_pos)
		wattroff(core->tui.process[i],
				COLOR_PAIR(core->proc_list[i]->warr->color_p) | A_BOLD);
	else
		wattroff(core->tui.process[i], COLOR_PAIR(1) | A_DIM);
	wrefresh(core->tui.process[i]);
}

void				update_proc_list(t_corewar *core)
{
	int				i;

	i = 0;
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	wclear(core->tui.proc_list);
	box(core->tui.proc_list, 0, 0);
	wrefresh(core->tui.proc_list);
	while (i < core->proc_list_len && i < MAX_PROC_IN_LIST)
	{
		if (!(core->proc_list[i]))
			return ;
		update_proc_list2(core, i);
		i++;
	}
}
