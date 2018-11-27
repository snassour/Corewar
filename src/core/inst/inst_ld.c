/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:38:17 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 22:19:16 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

int			inst_ld(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	int32_t	param;
	int32_t	reg;
	uint8_t	*mem;
	int		param_size;

	if ((mem = load_mem_inst(core, warr, proc)) == NULL)
		return (ERROR);
	param_size = (param_type(mem[1], 1) == TYPE_DIR) ? VM_DIR_SIZE \
		: VM_IND_SIZE;
	param = bytes_to_int(&(mem[2]), param_size);
	reg = bytes_to_int(&(mem[2 + param_size]), 1);
	if (is_reg_regular(reg) != SUCCESS)
		return (inst_set_pc_error(core, proc, 3, param_size));
	if (param_size == VM_IND_SIZE)
	{
		param %= VM_IDX_MOD;
		proc->reg[reg] = bytes_to_int(read_mem(core, proc->reg[REG_PC] \
			+ param), VM_REG_SIZE);
	}
	else if (param_size == VM_DIR_SIZE)
		proc->reg[reg] = param;
	proc->reg[REG_CF] = (proc->reg[reg] == 0) ? 1 : 0;
	return (inst_set_pc_success(core, proc, 2, param_size + 1));
}
