/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_vproc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:08:20 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 22:27:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		exec_vproc(t_corewar *core, t_vproc *proc)
{
	uint8_t	*mem;

	if (proc->wait_cycle == 0)
	{
		if ((core->flag & FLAG_T) != 0)
			copy_register(proc->reg_bf, proc->reg);
		core->inst_func[proc->inst](core, proc->warr, proc);
		mem = read_mem(core, proc->reg[REG_PC]);
		proc->inst = inst_id(mem[0]);
		proc->wait_cycle = core->inst_cycle[proc->inst];
	}
	else
		proc->wait_cycle--;
}
