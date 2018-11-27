/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_write_mem_tog.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:15:07 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:16:03 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static int	get_op_attr(chtype c)
{
	int				i;

	if ((c & A_COLOR) == 0 || (c & A_COLOR) == COLOR_PAIR(1))
		return (COLOR_PAIR(10));
	else if ((c & A_COLOR) == COLOR_PAIR(10))
		return (COLOR_PAIR(1));
	i = 2;
	while (i < 11)
	{
		if ((c & A_COLOR) == COLOR_PAIR(i))
		{
			if (i < 6)
				return (COLOR_PAIR(i + 4));
			else
				return (COLOR_PAIR(i - 4));
		}
		i++;
	}
	return (0);
}

void				tui_write_mem_tog(t_warrior *warr, t_uint location,
		uint8_t memory)
{
	int				pos[2];
	int				space;
	chtype			col;
	int				oposit;
	int				attr;

	if (!warr)
		return ;
	if (location >= VM_MEM_SIZE)
		location = location % VM_MEM_SIZE;
	pos[POS_X] = (location % 64);
	pos[POS_Y] = (location / 64);
	space = (2 * pos[POS_X]);
	col = mvwinch(*(warr->mem_win), pos[POS_Y] + BORDER_Y,\
	(pos[POS_X] + BORDER_X) + space);
	oposit = get_op_attr(col);
	attr = ((col & A_ATTRIBUTES) & A_DIM) ? A_DIM : A_BOLD;
	wattron(*(warr->mem_win), oposit | attr);
	wmove(*(warr->mem_win), pos[POS_Y] + BORDER_Y,\
	(pos[POS_X] + BORDER_X) + space);
	wprintw(*(warr->mem_win), "%02hhx", memory);
	wattroff(*(warr->mem_win), oposit | attr);
	if ((pos[POS_X] % 2) == 0)
		wprintw(*(warr->mem_win), " ");
	*(warr->mem_change) += 1;
}
