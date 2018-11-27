/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:26:55 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/08 23:36:43 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static inline void	init_warr(t_corewar *core, t_warrior *warr, int serial)
{
	ft_memset(warr->name, 0, VM_PROG_NAME_LENGTH + 1);
	ft_memset(warr->comm, 0, VM_COMMENT_LENGTH + 1);
	ft_memset(warr->inst, 0, VM_MAX_INST_SIZE + 1);
	warr->file_name = NULL;
	warr->warr_nb = 0;
	warr->serial = serial;
	warr->color_p = serial + 2;
	warr->color_p_pc = serial + 6;
	warr->warr_load_addr = 0;
	warr->inst_len = 0;
	warr->proc_start = NULL;
	warr->mem_share = (uint8_t *)&(core->memory);
	warr->flag = &(core->flag);
	warr->mem_win = &(core->mem_win);
	warr->inf_win = &(core->inf_win);
	warr->mem_change = &(core->mem_change);
}

static inline void	init_inst_cycle(int *inst_cycle)
{
	inst_cycle[INST_LIVE] = 10;
	inst_cycle[INST_LD] = 5;
	inst_cycle[INST_ST] = 4;
	inst_cycle[INST_ADD] = 10;
	inst_cycle[INST_SUB] = 10;
	inst_cycle[INST_AND] = 6;
	inst_cycle[INST_OR] = 6;
	inst_cycle[INST_XOR] = 6;
	inst_cycle[INST_ZJMP] = 20;
	inst_cycle[INST_LDI] = 25;
	inst_cycle[INST_STI] = 25;
	inst_cycle[INST_FORK] = 800;
	inst_cycle[INST_LLD] = 10;
	inst_cycle[INST_LLDI] = 50;
	inst_cycle[INST_LFORK] = 1000;
	inst_cycle[INST_AFF] = 2;
	inst_cycle[INST_NOP] = 0;
}

static inline void	init_inst_func(t_corewar *core)
{
	core->inst_func[INST_LIVE] = inst_live;
	core->inst_func[INST_LD] = inst_ld;
	core->inst_func[INST_ST] = inst_st;
	core->inst_func[INST_ADD] = inst_add;
	core->inst_func[INST_SUB] = inst_sub;
	core->inst_func[INST_AND] = inst_and;
	core->inst_func[INST_OR] = inst_or;
	core->inst_func[INST_XOR] = inst_xor;
	core->inst_func[INST_ZJMP] = inst_zjmp;
	core->inst_func[INST_LDI] = inst_ldi;
	core->inst_func[INST_STI] = inst_sti;
	core->inst_func[INST_FORK] = inst_fork;
	core->inst_func[INST_LLD] = inst_lld;
	core->inst_func[INST_LLDI] = inst_lldi;
	core->inst_func[INST_LFORK] = inst_lfork;
	core->inst_func[INST_AFF] = inst_aff;
	core->inst_func[INST_NOP] = ints_nop;
}

void				init_core(t_corewar *cor)
{
	int				l;

	l = 0;
	ft_memset(cor->memory, 0, VM_MEM_SIZE);
	init_warr(cor, &(cor->warr[0]), 0);
	init_warr(cor, &(cor->warr[1]), 1);
	init_warr(cor, &(cor->warr[2]), 2);
	init_warr(cor, &(cor->warr[3]), 3);
	init_inst_cycle(cor->inst_cycle);
	init_inst_func(cor);
	cor->max_warr = 0;
	cor->cycle = 0;
	cor->max_cycle = 0;
	cor->cycle_to_die = VM_CYCLE_TO_DIE;
	cor->live_warr_nb = -1;
	cor->proc_q = NULL;
	cor->proc_q_len = 0;
	while (l < MAX_PROC_IN_LIST)
		cor->proc_list[l++] = NULL;
	init_core_dos(cor);
	init_core_tres(cor);
}
