/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_and_gen_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:03:19 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/07 18:28:26 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_add.h"

int					inst_and_set_pc(t_corewar *core, t_vproc *proc,
		int32_t *p_s)
{
	set_pc(core, proc, proc->reg[REG_PC] + 2 + p_s[0] + p_s[1] + p_s[2], 0);
	return (ERROR);
}

uint8_t				*inst_and_gen_mem(t_corewar *core, t_warrior *warr,
		t_vproc *proc)
{
	uint8_t			*m;

	if (!core || !warr || !proc)
		return (NULL);
	m = read_mem(core, proc->reg[REG_PC]);
	return (m);
}
