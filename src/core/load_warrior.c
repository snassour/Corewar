/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_warrior.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:03:57 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:05:16 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	set_warr_load_addr(t_corewar *core)
{
	t_uint i;

	i = 0;
	if (!core)
		return (ERROR);
	while (i < core->max_warr)
	{
		core->warr[i].warr_load_addr = i * (VM_MEM_SIZE / core->max_warr);
		core->warr[i].proc_start = vproc_new(&(core->warr[i]), \
			core->warr[i].warr_load_addr);
		if (core->warr[i].proc_start == NULL)
			return (ERROR);
		core->warr[i].proc_start->reg[REG_R1] = core->warr[i].warr_nb;
		vproc_push(core, core->warr[i].proc_start);
		i++;
	}
	return (SUCCESS);
}

int					load_warrior(t_corewar *core)
{
	t_uint			i;

	if (!core)
		return (ERROR);
	i = 0;
	if (set_warr_load_addr(core) == ERROR)
		return (ERROR);
	while (i < core->max_warr)
	{
		if (core->warr[i].inst_len > 0)
		{
			write_mem(&(core->warr[i]), core->warr[i].warr_load_addr, \
				core->warr[i].inst, core->warr[i].inst_len);
		}
		i++;
	}
	return (SUCCESS);
}
