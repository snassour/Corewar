/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:07:51 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/08 23:37:09 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	clear_players(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	if ((core->flag & FLAG_T) != 0)
	{
		wclear(core->tui.p_num[0]);
		wclear(core->tui.p_num[1]);
		wclear(core->tui.p_num[2]);
		wclear(core->tui.p_num[3]);
		wclear(core->tui.p_name[0]);
		wclear(core->tui.p_name[1]);
		wclear(core->tui.p_name[2]);
		wclear(core->tui.p_name[3]);
		wrefresh(core->tui.p_num[0]);
		wrefresh(core->tui.p_num[1]);
		wrefresh(core->tui.p_num[2]);
		wrefresh(core->tui.p_num[3]);
		wrefresh(core->tui.p_name[0]);
		wrefresh(core->tui.p_name[1]);
		wrefresh(core->tui.p_name[2]);
		wrefresh(core->tui.p_name[3]);
	}
}

static inline void	show_winner_tui(t_corewar *core, int i)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	box(core->tui.p_name[i], 0, 0);
	box(core->tui.p_num[i], 0, 0);
	wattron(core->tui.p_name[i], COLOR_PAIR(i + 2) | A_BOLD);
	wattron(core->tui.p_num[i], COLOR_PAIR(i + 2) | A_BOLD);
	mvwprintw(core->tui.p_num[0], 1, 2, "%d", core->warr[0].warr_nb);
	mvwprintw(core->tui.p_name[0], 1, 2, "%.49s", p_name(core->warr[i].name));
	wattroff(core->tui.p_num[i], COLOR_PAIR(i + 2) | A_BOLD);
	wattroff(core->tui.p_name[i], COLOR_PAIR(i + 2) | A_BOLD);
	wrefresh(core->tui.p_num[i]);
	wrefresh(core->tui.p_name[i]);
}

void				show_winner(t_corewar *core)
{
	int				i;

	if (!core)
		return ;
	i = -1;
	while (++i < 4)
		if (core->warr[i].warr_nb == core->live_warr_nb)
			break ;
	clear_players(core);
	if (i == 4 || (i < 4 && core->warr[i].warr_nb != core->live_warr_nb))
	{
		if ((core->flag & FLAG_T) == 0)
			ft_printf("No warrior won. Winner number is %d\n", \
			core->live_warr_nb);
	}
	else
	{
		if ((core->flag & FLAG_T) == 0)
			ft_printf("Le joueur %d (%s)  a gagné.\n", \
				core->warr[i].warr_nb, core->warr[i].name);
		else
			show_winner_tui(core, i);
	}
}
