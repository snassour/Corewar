/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:12:11 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 10:18:18 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			inst_add(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	uint8_t	*mem;
	uint8_t	param[3];

	if (!core || !warr || !proc)
		return (ERROR);
	mem = read_mem(core, proc->reg[REG_PC]);
	if (is_reg_regular(mem[2]) == ERROR \
		|| is_reg_regular(mem[3]) == ERROR \
		|| is_reg_regular(mem[4]) == ERROR)
	{
		set_pc(core, proc, proc->reg[REG_PC] + 4 + 1, 0);
		return (ERROR);
	}
	param[0] = mem[2];
	param[1] = mem[3];
	param[2] = mem[4];
	proc->reg[param[2]] = proc->reg[param[0]] + proc->reg[param[1]];
	set_pc(core, proc, proc->reg[REG_PC] + 4 + 1, 0);
	proc->reg[REG_CF] = (proc->reg[param[2]] == 0) ? 1 : 0;
	return (SUCCESS);
}
