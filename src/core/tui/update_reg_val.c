/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_reg_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:53:14 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:55:19 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				update_reg_val(WINDOW **regw, int32_t *reg)
{
	int				i;

	i = 0;
	mvwprintw((regw[REG_PC]), 1, 1, "%*d", 21, reg[REG_PC]);
	mvwprintw((regw[REG_R1]), 1, 1, "%*d", 21, reg[REG_R1]);
	mvwprintw((regw[REG_R2]), 1, 1, "%*d", 21, reg[REG_R2]);
	mvwprintw((regw[REG_R3]), 1, 1, "%*d", 21, reg[REG_R3]);
	mvwprintw((regw[REG_R4]), 1, 1, "%*d", 21, reg[REG_R4]);
	mvwprintw((regw[REG_R5]), 1, 1, "%*d", 21, reg[REG_R5]);
	mvwprintw((regw[REG_R6]), 1, 1, "%*d", 21, reg[REG_R6]);
	mvwprintw((regw[REG_R7]), 1, 1, "%*d", 21, reg[REG_R7]);
	mvwprintw((regw[REG_R8]), 1, 1, "%*d", 21, reg[REG_R8]);
	mvwprintw((regw[REG_R9]), 1, 1, "%*d", 21, reg[REG_R9]);
	mvwprintw((regw[REG_R10]), 1, 1, "%*d", 21, reg[REG_R10]);
	mvwprintw((regw[REG_R11]), 1, 1, "%*d", 21, reg[REG_R11]);
	mvwprintw((regw[REG_R12]), 1, 1, "%*d", 21, reg[REG_R12]);
	mvwprintw((regw[REG_R13]), 1, 1, "%*d", 21, reg[REG_R13]);
	mvwprintw((regw[REG_R14]), 1, 1, "%*d", 21, reg[REG_R14]);
	mvwprintw((regw[REG_R15]), 1, 1, "%*d", 21, reg[REG_R15]);
	mvwprintw((regw[REG_R16]), 1, 1, "%*d", 21, reg[REG_R16]);
	mvwprintw((regw[REG_CF]), 1, 1, "%*d", 21, reg[REG_CF]);
	while (i < VM_MAX_REG_NUMBER)
		wrefresh(regw[i++]);
}
