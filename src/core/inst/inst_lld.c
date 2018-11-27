/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:04:24 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 11:07:15 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			inst_lld(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	int32_t	param;
	uint8_t	*mem;
	int32_t	reg;
	int		param_size;

	if (!core || !warr || !proc)
		return (ERROR);
	mem = read_mem(core, proc->reg[REG_PC]);
	param_size = (param_type(mem[1], 1) == TYPE_DIR) ? VM_DIR_SIZE \
		: VM_IND_SIZE;
	param = bytes_to_int(&(mem[2]), param_size);
	reg = bytes_to_int(&(mem[2 + param_size]), 1);
	if (is_reg_regular(reg) != SUCCESS)
	{
		set_pc(core, proc, proc->reg[REG_PC] + 2 + param_size + 1, 0);
		return (ERROR);
	}
	if (param_size == VM_IND_SIZE)
		proc->reg[reg] = bytes_to_int(read_mem(core, proc->reg[REG_PC] \
			+ param), VM_REG_SIZE);
	else if (param_size == VM_DIR_SIZE)
		proc->reg[reg] = param;
	set_pc(core, proc, proc->reg[REG_PC] + 2 + param_size + 1, 0);
	proc->reg[REG_CF] = (proc->reg[reg] == 0) ? 1 : 0;
	return (SUCCESS);
}
