/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 10:18:45 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 10:20:27 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				inst_aff(t_corewar *core, t_warrior *warr, t_vproc *proc)
{
	uint32_t	param;
	char		ascii;
	uint8_t		*mem;

	param = 0;
	mem = NULL;
	ascii = 0;
	if (!core || !warr || !proc)
		return (ERROR);
	mem = read_mem(core, proc->reg[REG_PC]);
	param = bytes_to_int(&(mem[2]), VM_REGISTER_SIZE);
	if (is_reg_regular(param) == ERROR)
	{
		set_pc(core, proc, proc->reg[REG_PC] + 3, 0);
		return (ERROR);
	}
	ascii = proc->reg[param] % 256;
	if ((core->flag & FLAG_T) == 0)
		write(1, &ascii, 1);
	set_pc(core, proc, proc->reg[REG_PC] + 3, 0);
	return (SUCCESS);
	(void)param;
}
