/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_nop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:13:43 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 11:14:36 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	ints_nop(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	if (!core || !warr || !proc)
		return (ERROR);
	set_pc(core, proc, proc->reg[REG_PC] + 1, 0);
	return (SUCCESS);
}
