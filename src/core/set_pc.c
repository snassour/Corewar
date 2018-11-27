/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:06:05 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:18:43 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			set_pc(t_corewar *core, t_vproc *proc, \
	int32_t location, int flag)
{
	uint32_t	located;
	uint8_t		old_mem;
	uint8_t		new_mem;

	if (location < 0)
	{
		location = (location % VM_MEM_SIZE) * -1;
		location = VM_MEM_SIZE - location;
	}
	if (location >= VM_MEM_SIZE)
		location = location % VM_MEM_SIZE;
	located = proc->reg[REG_PC];
	proc->reg[REG_PC] = location;
	if ((*(proc->warr->flag) & FLAG_T) == 0)
		return ;
	if (flag != FORK_PROC_FLAG)
	{
		old_mem = *(read_mem(core, located));
		tui_write_mem_tog(proc->warr, located, old_mem);
	}
	new_mem = *(read_mem(core, proc->reg[REG_PC]));
	if (flag == NORM_PROC_FLAG || flag == FORK_PROC_FLAG)
		tui_write_mem_tog(proc->warr, proc->reg[REG_PC], new_mem);
	else if (flag == SPEC_PROC_FLAG)
		tui_write_mem_spe(proc->warr, proc->reg[REG_PC], new_mem);
}
