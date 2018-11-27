/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:34:39 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 23:06:54 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline void	init_proc_reg(int32_t *dest, int32_t *src)
{
	dest[REG_R1] = src[REG_R1];
	dest[REG_R2] = src[REG_R2];
	dest[REG_R3] = src[REG_R3];
	dest[REG_R4] = src[REG_R4];
	dest[REG_R5] = src[REG_R5];
	dest[REG_R6] = src[REG_R6];
	dest[REG_R7] = src[REG_R7];
	dest[REG_R8] = src[REG_R8];
	dest[REG_R9] = src[REG_R9];
	dest[REG_R10] = src[REG_R10];
	dest[REG_R11] = src[REG_R11];
	dest[REG_R12] = src[REG_R12];
	dest[REG_R13] = src[REG_R13];
	dest[REG_R14] = src[REG_R14];
	dest[REG_R15] = src[REG_R15];
	dest[REG_R16] = src[REG_R16];
	dest[REG_CF] = src[REG_CF];
}

int					inst_fork(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	uint8_t			*mem;
	int32_t			param;
	t_vproc			*nproc;

	if (!core || !warr || !proc)
		return (ERROR);
	mem = read_mem(core, proc->reg[REG_PC]);
	param = bytes_to_int(&(mem[1]), VM_IND_SIZE) % VM_IDX_MOD;
	nproc = NULL;
	if (!(nproc = vproc_new(warr, proc->reg[REG_PC] + param)))
	{
		set_pc(core, proc, proc->reg[REG_PC] + VM_IND_SIZE + 1, 0);
		return (ERROR);
	}
	init_proc_reg(nproc->reg, proc->reg);
	set_pc(core, nproc, proc->reg[REG_PC] + param, FORK_PROC_FLAG);
	mem = read_mem(core, nproc->reg[REG_PC]);
	nproc->inst = inst_id(mem[0]);
	nproc->wait_cycle = core->inst_cycle[nproc->inst];
	nproc->live = proc->live;
	vproc_push(core, nproc);
	set_pc(core, proc, proc->reg[REG_PC] + VM_IND_SIZE + 1, 0);
	return (SUCCESS);
}
