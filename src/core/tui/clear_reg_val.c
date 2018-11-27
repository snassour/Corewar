/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_reg_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:12:07 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:12:49 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				clear_reg_val(WINDOW **regw)
{
	int				i;

	i = 0;
	mvwprintw((regw[REG_PC]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R1]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R2]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R3]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R4]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R5]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R6]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R7]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R8]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R9]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R10]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R11]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R12]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R13]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R14]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R15]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_R16]), 1, 1, "%*c", 21, ' ');
	mvwprintw((regw[REG_CF]), 1, 1, "%*c", 21, ' ');
	while (i < VM_MAX_REG_NUMBER)
		wrefresh(regw[i++]);
}
