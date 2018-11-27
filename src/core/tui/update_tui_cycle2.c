/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tui_cycle2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:52:39 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 19:39:11 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				update_cycle(t_corewar *core)
{
	if (!core || (core->flag & FLAG_T) == 0)
		return ;
	mvwprintw(core->tui.cycle_val, 1, 2, "%26d", core->cycle);
	wrefresh(core->tui.cycle_val);
}
