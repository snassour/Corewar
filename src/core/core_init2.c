/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:23:07 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/07 18:14:20 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

void		init_core_tres(t_corewar *cor)
{
	cor->tui.proc_head = NULL;
	cor->tui.proc_list = NULL;
	ft_memset(cor->tui.process, 0, MAX_PROC_IN_LIST);
	cor->tui.proc_box = NULL;
	cor->tui.reg_bf_box = NULL;
	ft_memset(cor->tui.reg_bf_name, 0, VM_MAX_REG_NUMBER);
	ft_memset(cor->tui.reg_bf, 0, VM_MAX_REG_NUMBER);
	cor->tui.reg_af_box = NULL;
	ft_memset(cor->tui.reg_af_name, 0, VM_MAX_REG_NUMBER);
	ft_memset(cor->tui.reg_af, 0, VM_MAX_REG_NUMBER);
	cor->tui.input = NULL;
	cor->tui.output = NULL;
	cor->mem_win = NULL;
	cor->inf_win = NULL;
	cor->mem_change = 0;
	cor->pause = 0;
	cor->flag = 0;
	cor->dump = -1;
	cor->exec_stat = DEFAULT_STAT;
	cor->exec_speed = DEFAULT_SPEED;
	cor->exec_wait_time.tv_sec = 0;
	cor->exec_wait_time.tv_nsec = 0;
	cor->exec_set_time.tv_sec = 0;
	cor->exec_set_time.tv_nsec = 0;
}

void		init_core_dos(t_corewar *cor)
{
	cor->proc_list_len = 0;
	cor->proc_list_pos = 0;
	cor->can_load_q = 0;
	cor->tui.stat = NULL;
	cor->tui.next = NULL;
	cor->tui.speed = NULL;
	cor->tui.high = NULL;
	cor->tui.low = NULL;
	cor->tui.p_num[0] = NULL;
	cor->tui.p_num[1] = NULL;
	cor->tui.p_num[2] = NULL;
	cor->tui.p_num[3] = NULL;
	cor->tui.p_name[0] = NULL;
	cor->tui.p_name[1] = NULL;
	cor->tui.p_name[2] = NULL;
	cor->tui.p_name[3] = NULL;
	cor->tui.cycle = NULL;
	cor->tui.cycle_val = NULL;
	cor->tui.cycle_to_die = NULL;
	cor->tui.cycle_to_die_val = NULL;
	cor->tui.live = NULL;
	cor->tui.live_val = NULL;
	cor->tui.max_proc = NULL;
	cor->tui.max_proc_val = NULL;
}
