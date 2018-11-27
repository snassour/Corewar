/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui_reg_bf_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:39:48 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:47:53 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static void			init_reg_bf_name3(t_corewar *core)
{
	core->tui.reg_bf_name[15] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME15_ORGN_Y,
			TUI_REG_BF_NAME15_ORGN_X);
	core->tui.reg_bf_name[16] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME16_ORGN_Y,
			TUI_REG_BF_NAME16_ORGN_X);
	core->tui.reg_bf_name[17] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME17_ORGN_Y,
			TUI_REG_BF_NAME17_ORGN_X);
}

static void			init_reg_bf_name2(t_corewar *core)
{
	core->tui.reg_bf_name[8] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME8_ORGN_Y,
			TUI_REG_BF_NAME8_ORGN_X);
	core->tui.reg_bf_name[9] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME9_ORGN_Y,
			TUI_REG_BF_NAME9_ORGN_X);
	core->tui.reg_bf_name[10] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME10_ORGN_Y,
			TUI_REG_BF_NAME10_ORGN_X);
	core->tui.reg_bf_name[11] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME11_ORGN_Y,
			TUI_REG_BF_NAME11_ORGN_X);
	core->tui.reg_bf_name[12] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME12_ORGN_Y,
			TUI_REG_BF_NAME12_ORGN_X);
	core->tui.reg_bf_name[13] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME13_ORGN_Y,
			TUI_REG_BF_NAME13_ORGN_X);
	core->tui.reg_bf_name[14] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME14_ORGN_Y,
			TUI_REG_BF_NAME14_ORGN_X);
	init_reg_bf_name3(core);
}

void				init_reg_bf_name(t_corewar *core)
{
	core->tui.reg_bf_name[0] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME0_ORGN_Y,
			TUI_REG_BF_NAME0_ORGN_X);
	core->tui.reg_bf_name[1] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME1_ORGN_Y,
			TUI_REG_BF_NAME1_ORGN_X);
	core->tui.reg_bf_name[2] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME2_ORGN_Y,
			TUI_REG_BF_NAME2_ORGN_X);
	core->tui.reg_bf_name[3] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME3_ORGN_Y,
			TUI_REG_BF_NAME3_ORGN_X);
	core->tui.reg_bf_name[4] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME4_ORGN_Y,
			TUI_REG_BF_NAME4_ORGN_X);
	core->tui.reg_bf_name[5] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME5_ORGN_Y,
			TUI_REG_BF_NAME5_ORGN_X);
	core->tui.reg_bf_name[6] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME6_ORGN_Y,
			TUI_REG_BF_NAME6_ORGN_X);
	core->tui.reg_bf_name[7] = newwin(TUI_REG_BF_NAME_HEIGHT,
			TUI_REG_BF_NAME_WIDTH, TUI_REG_BF_NAME7_ORGN_Y,
			TUI_REG_BF_NAME7_ORGN_X);
	init_reg_bf_name2(core);
}
