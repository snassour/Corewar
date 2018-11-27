/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:36:54 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 11:37:43 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			inst_zjmp(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	int32_t	param;
	uint8_t	*mem;

	param = 0;
	mem = NULL;
	if (!core || !warr || !proc)
		return (ERROR);
	mem = read_mem(core, proc->reg[REG_PC]);
	param = bytes_to_int(&(mem[1]), VM_IND_SIZE) % VM_IDX_MOD;
	if (proc->reg[REG_CF] == 1)
		set_pc(core, proc, proc->reg[REG_PC] + param, 0);
	else
		set_pc(core, proc, proc->reg[REG_PC] + VM_IND_SIZE + 1, 0);
	return (SUCCESS);
}
