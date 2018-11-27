/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_load_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:31:07 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/07 19:11:39 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

uint8_t				*load_mem_inst(t_corewar *core, t_warrior *warr,
		t_vproc *proc)
{
	if (!core || !warr || !proc)
		return (NULL);
	return (read_mem(core, proc->reg[REG_PC]));
}
