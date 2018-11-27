/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:19:41 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:56:27 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

int			inst_st(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	int32_t	reg;
	int32_t	param;
	uint8_t	*mem;
	int		param_size;

	if ((mem = load_mem_inst(core, warr, proc)) == NULL)
		return (ERROR);
	reg = bytes_to_int(&(mem[2]), 1);
	param_size = (param_type(mem[1], 2) == TYPE_REG) ? VM_REGISTER_SIZE \
		: VM_IND_SIZE;
	param = bytes_to_int(&(mem[3]), param_size);
	if (is_reg_regular(reg) != SUCCESS)
		return (inst_set_pc_success(core, proc, 3, param_size));
	if (param_size == VM_REGISTER_SIZE && is_reg_regular(param) != SUCCESS)
		return (inst_set_pc_success(core, proc, 3, param_size));
	if (param_size == VM_IND_SIZE)
	{
		param %= VM_IDX_MOD;
		write_mem(warr, proc->reg[REG_PC] + param, int_to_bytes(proc->reg[reg],\
			VM_REG_SIZE), VM_REG_SIZE);
	}
	else if (param_size == VM_REGISTER_SIZE)
		proc->reg[param] = proc->reg[reg];
	return (inst_set_pc_success(core, proc, 3, param_size));
}
