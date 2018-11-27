/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_set_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:32:55 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/07 18:34:48 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

int32_t			inst_set_param0(t_corewar *core, t_vproc *proc, int32_t *type,
		int32_t *param)
{
	if (type[0] == TYPE_IND)
		param[0] = bytes_to_int(read_mem(core, proc->reg[REG_PC] \
			+ param[0]), VM_REG_SIZE);
	return (param[0]);
}

int32_t			inst_set_param1(t_corewar *core, t_vproc *proc, int32_t *type,
		int32_t *param)
{
	if (type[1] == TYPE_IND)
		param[1] = bytes_to_int(read_mem(core, proc->reg[REG_PC] \
			+ param[1]), VM_REG_SIZE);
	return (param[1]);
}
