/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vproc_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:12:54 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 21:30:01 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void static inline	ext_init_vproc_q(t_corewar *core, t_vproc *save)
{
	int i;

	i = 0;
	core->can_load_q = 1;
	core->proc_list_len = 0;
	ft_memset(core->proc_list, 0, MAX_PROC_IN_LIST);
	while (save && i < MAX_PROC_IN_LIST)
	{
		core->proc_list[i] = save;
		core->proc_list_len++;
		save = save->next;
		i++;
	}
	update_proc_list(core);
	update_proc_reg_info(core);
	update_max_process(core);
	wrefresh(core->mem_win);
}

void				init_vproc_q(t_corewar *core, t_vproc *proc)
{
	t_vproc	*save;
	uint8_t	*mem;

	save = proc;
	if (!core || !proc)
		return ;
	while (proc)
	{
		set_pc(core, proc, proc->reg[REG_PC], 1);
		mem = read_mem(core, proc->reg[REG_PC]);
		proc->inst = inst_id(mem[0]);
		proc->wait_cycle = core->inst_cycle[proc->inst];
		proc = proc->next;
	}
	if ((core->flag & FLAG_T) != 0)
		ext_init_vproc_q(core, save);
}
