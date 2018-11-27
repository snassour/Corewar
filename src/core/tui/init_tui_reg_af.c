/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui_reg_af.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:53:13 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 15:53:15 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static void			init_reg_af2(t_corewar *core)
{
	core->tui.reg_af[11] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF11_ORGN_Y, TUI_REG_AF11_ORGN_X);
	core->tui.reg_af[12] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF12_ORGN_Y, TUI_REG_AF12_ORGN_X);
	core->tui.reg_af[13] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF13_ORGN_Y, TUI_REG_AF13_ORGN_X);
	core->tui.reg_af[14] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF14_ORGN_Y, TUI_REG_AF14_ORGN_X);
	core->tui.reg_af[15] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF15_ORGN_Y, TUI_REG_AF15_ORGN_X);
	core->tui.reg_af[16] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF16_ORGN_Y, TUI_REG_AF16_ORGN_X);
	core->tui.reg_af[17] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF17_ORGN_Y, TUI_REG_AF17_ORGN_X);
}

void				init_reg_af(t_corewar *core)
{
	core->tui.reg_af[0] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF0_ORGN_Y, TUI_REG_AF0_ORGN_X);
	core->tui.reg_af[1] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF1_ORGN_Y, TUI_REG_AF1_ORGN_X);
	core->tui.reg_af[2] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF2_ORGN_Y, TUI_REG_AF2_ORGN_X);
	core->tui.reg_af[3] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF3_ORGN_Y, TUI_REG_AF3_ORGN_X);
	core->tui.reg_af[4] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF4_ORGN_Y, TUI_REG_AF4_ORGN_X);
	core->tui.reg_af[5] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF5_ORGN_Y, TUI_REG_AF5_ORGN_X);
	core->tui.reg_af[6] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF6_ORGN_Y, TUI_REG_AF6_ORGN_X);
	core->tui.reg_af[7] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF7_ORGN_Y, TUI_REG_AF7_ORGN_X);
	core->tui.reg_af[8] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF8_ORGN_Y, TUI_REG_AF8_ORGN_X);
	core->tui.reg_af[9] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF9_ORGN_Y, TUI_REG_AF9_ORGN_X);
	core->tui.reg_af[10] = newwin(TUI_REG_AF_HEIGHT, TUI_REG_AF_WIDTH,
			TUI_REG_AF10_ORGN_Y, TUI_REG_AF10_ORGN_X);
	init_reg_af2(core);
}
