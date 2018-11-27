/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_set_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:36:05 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/07 22:18:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

int			inst_set_pc_error(t_corewar *core, t_vproc *proc, int32_t val,
		int val2)
{
	set_pc(core, proc, proc->reg[REG_PC] + val + val2, 0);
	return (ERROR);
}

int			inst_set_pc_success(t_corewar *core, t_vproc *proc, int32_t val,
		int val2)
{
	set_pc(core, proc, proc->reg[REG_PC] + val + val2, 0);
	return (SUCCESS);
}
