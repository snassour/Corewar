/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui_reg_bf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:39:22 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:39:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static void			init_reg_bf2(t_corewar *core)
{
	core->tui.reg_bf[12] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF12_ORGN_Y, TUI_REG_BF12_ORGN_X);
	core->tui.reg_bf[13] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF13_ORGN_Y, TUI_REG_BF13_ORGN_X);
	core->tui.reg_bf[14] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF14_ORGN_Y, TUI_REG_BF14_ORGN_X);
	core->tui.reg_bf[15] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF15_ORGN_Y, TUI_REG_BF15_ORGN_X);
	core->tui.reg_bf[16] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF16_ORGN_Y, TUI_REG_BF16_ORGN_X);
	core->tui.reg_bf[17] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF17_ORGN_Y, TUI_REG_BF17_ORGN_X);
}

void				init_reg_bf(t_corewar *core)
{
	core->tui.reg_bf[0] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF0_ORGN_Y, TUI_REG_BF0_ORGN_X);
	core->tui.reg_bf[1] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF1_ORGN_Y, TUI_REG_BF1_ORGN_X);
	core->tui.reg_bf[2] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF2_ORGN_Y, TUI_REG_BF2_ORGN_X);
	core->tui.reg_bf[3] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF3_ORGN_Y, TUI_REG_BF3_ORGN_X);
	core->tui.reg_bf[4] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF4_ORGN_Y, TUI_REG_BF4_ORGN_X);
	core->tui.reg_bf[5] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF5_ORGN_Y, TUI_REG_BF5_ORGN_X);
	core->tui.reg_bf[6] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF6_ORGN_Y, TUI_REG_BF6_ORGN_X);
	core->tui.reg_bf[7] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF7_ORGN_Y, TUI_REG_BF7_ORGN_X);
	core->tui.reg_bf[8] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF8_ORGN_Y, TUI_REG_BF8_ORGN_X);
	core->tui.reg_bf[9] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF9_ORGN_Y, TUI_REG_BF9_ORGN_X);
	core->tui.reg_bf[10] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF10_ORGN_Y, TUI_REG_BF10_ORGN_X);
	core->tui.reg_bf[11] = newwin(TUI_REG_BF_HEIGHT, TUI_REG_BF_WIDTH,
			TUI_REG_BF11_ORGN_Y, TUI_REG_BF11_ORGN_X);
	init_reg_bf2(core);
}
