/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_write_mem_nor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:13:39 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:14:12 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				tui_write_mem_nor(t_warrior *warr, t_uint location,
		uint8_t memory)
{
	int				pos[2];
	int				space;

	if (!warr)
		return ;
	if (location >= VM_MEM_SIZE)
		location = location % VM_MEM_SIZE;
	space = 0;
	pos[POS_X] = 0;
	pos[POS_Y] = 0;
	wattron(*(warr->mem_win), COLOR_PAIR(warr->color_p) | A_BOLD);
	pos[POS_X] = (location % 64);
	pos[POS_Y] = (location / 64);
	space = (2 * pos[POS_X]);
	wmove(*(warr->mem_win), pos[POS_Y] + BORDER_Y, (pos[POS_X] + BORDER_X) +
			space);
	wprintw(*(warr->mem_win), "%02hhx", memory);
	wattroff(*(warr->mem_win), COLOR_PAIR(warr->color_p) | A_BOLD);
	if ((pos[POS_X] % 2) == 0)
		wprintw(*(warr->mem_win), " ");
	*(warr->mem_change) += 1;
}
