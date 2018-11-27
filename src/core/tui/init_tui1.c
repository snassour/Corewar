/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tui1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:32:42 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 17:49:08 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void				init_core_p_numname(t_corewar *core)
{
	core->tui.p_num[0] = newwin(TUI_P1_NUM_HEIGHT, TUI_P1_NUM_WIDTH,
			TUI_P1_NUM_ORGN_Y, TUI_P1_NUM_ORGN_X);
	core->tui.p_num[1] = newwin(TUI_P2_NUM_HEIGHT, TUI_P2_NUM_WIDTH,
			TUI_P2_NUM_ORGN_Y, TUI_P2_NUM_ORGN_X);
	core->tui.p_num[2] = newwin(TUI_P3_NUM_HEIGHT, TUI_P3_NUM_WIDTH,
			TUI_P3_NUM_ORGN_Y, TUI_P3_NUM_ORGN_X);
	core->tui.p_num[3] = newwin(TUI_P4_NUM_HEIGHT, TUI_P4_NUM_WIDTH,
			TUI_P4_NUM_ORGN_Y, TUI_P4_NUM_ORGN_X);
	core->tui.p_name[0] = newwin(TUI_P1_NAME_HEIGHT, TUI_P1_NAME_WIDTH,
			TUI_P1_NAME_ORGN_Y, TUI_P1_NAME_ORGN_X);
	core->tui.p_name[1] = newwin(TUI_P2_NAME_HEIGHT, TUI_P2_NAME_WIDTH,
			TUI_P2_NAME_ORGN_Y, TUI_P2_NAME_ORGN_X);
	core->tui.p_name[2] = newwin(TUI_P3_NAME_HEIGHT, TUI_P3_NAME_WIDTH,
			TUI_P3_NAME_ORGN_Y, TUI_P3_NAME_ORGN_X);
	core->tui.p_name[3] = newwin(TUI_P4_NAME_HEIGHT, TUI_P4_NAME_WIDTH,
			TUI_P4_NAME_ORGN_Y, TUI_P4_NAME_ORGN_X);
}

void				init_core_process(t_corewar *core)
{
	core->tui.process[0] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS1_ORGN_Y, TUI_PROCESS1_ORGN_X);
	core->tui.process[1] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS2_ORGN_Y, TUI_PROCESS2_ORGN_X);
	core->tui.process[2] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS3_ORGN_Y, TUI_PROCESS3_ORGN_X);
	core->tui.process[3] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS4_ORGN_Y, TUI_PROCESS4_ORGN_X);
	core->tui.process[4] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS5_ORGN_Y, TUI_PROCESS5_ORGN_X);
	core->tui.process[5] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS6_ORGN_Y, TUI_PROCESS6_ORGN_X);
	core->tui.process[6] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS7_ORGN_Y, TUI_PROCESS7_ORGN_X);
	core->tui.process[7] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS8_ORGN_Y, TUI_PROCESS8_ORGN_X);
	core->tui.process[8] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS9_ORGN_Y, TUI_PROCESS9_ORGN_X);
	core->tui.process[9] = newwin(TUI_PROCESS_HEIGHT, TUI_PROCESS_WIDTH,
			TUI_PROCESS10_ORGN_Y, TUI_PROCESS10_ORGN_X);
	core->tui.proc_box = newwin(TUI_PROC_BOX_HEIGHT, TUI_PROC_BOX_WIDTH,
			TUI_PROC_BOX_ORGN_Y, TUI_PROC_BOX_ORGN_X);
}

int					create_windows(t_corewar *core)
{
	init_core2(core);
	init_core1(core);
	init_core_p_numname(core);
	init_core_process(core);
	init_reg_bf_name(core);
	init_reg_bf(core);
	init_reg_af(core);
	init_reg_af_name(core);
	init_box(core);
	return (check_data(core));
}
