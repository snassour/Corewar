/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:23:29 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:57:05 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

static inline int	set_param(int32_t *param, int32_t type, t_vproc *proc, \
	uint8_t *mem)
{
	if (type == TYPE_REG)
	{
		if (is_reg_regular(mem[0]) == ERROR)
			return (ERROR);
		*param = proc->reg[mem[0]];
	}
	else if (type == TYPE_DIR)
		*param = bytes_to_int(mem, VM_IND_SIZE);
	else if (type == TYPE_IND)
		*param = bytes_to_int(mem, VM_IND_SIZE) % VM_IDX_MOD;
	return (SUCCESS);
}

int					inst_sti(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	uint8_t			*mem;
	int32_t			param[3];
	int32_t			type[3];
	int32_t			p_s[3];

	if ((mem = load_mem_inst(core, warr, proc)) == NULL)
		return (ERROR);
	type[0] = param_type(mem[1], 1);
	type[1] = param_type(mem[1], 2);
	type[2] = param_type(mem[1], 3);
	p_s[0] = get_param_size(type[0]);
	p_s[1] = (type[1] == TYPE_DIR) ? 2 : get_param_size(type[1]);
	p_s[2] = (type[2] == TYPE_DIR) ? 2 : get_param_size(type[2]);
	if (type[2] != TYPE_DIR && type[2] != TYPE_REG)
		return (inst_set_pc_error(core, proc, 2, p_s[0] + p_s[1] + p_s[2]));
	if (is_reg_regular(mem[2]) == ERROR ||\
		set_param(&(param[1]), type[1], proc, &(mem[3])) == ERROR \
		|| set_param(&(param[2]), type[2], proc, &(mem[3 + p_s[1]])) == ERROR)
		return (inst_set_pc_error(core, proc, 2, p_s[0] + p_s[1] + p_s[2]));
	param[0] = mem[2];
	param[1] = inst_set_param1(core, proc, type, param);
	write_mem(warr, proc->reg[REG_PC] + ((param[1] + param[2]) % VM_IDX_MOD), \
		int_to_bytes(proc->reg[param[0]], VM_REG_SIZE), VM_REG_SIZE);
	set_pc(core, proc, proc->reg[REG_PC] + 2 + p_s[0] + p_s[1] + p_s[2], 0);
	return (inst_set_pc_success(core, proc, 2, p_s[0] + p_s[1] + p_s[2]));
}
