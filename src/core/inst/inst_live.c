/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:02:08 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 11:03:35 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			inst_live(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	int32_t	param;
	uint8_t	*mem;

	if (!core || !warr || !proc)
		return (ERROR);
	param = 0;
	mem = NULL;
	mem = read_mem(core, proc->reg[REG_PC] + 1);
	param = bytes_to_int(&(mem[0]), VM_DIR_SIZE);
	proc->live++;
	core->live_count++;
	core->live_warr_nb = param;
	update_live(core);
	if ((core->flag & FLAG_T) == 0)
		ft_printf("Le joueur %d (%s) est en vie.\n", warr->warr_nb, warr->name);
	set_pc(core, proc, proc->reg[REG_PC] + VM_DIR_SIZE + 1, 0);
	return (SUCCESS);
}
