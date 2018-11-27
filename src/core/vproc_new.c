/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vproc_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:10:48 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:15:07 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vproc		*vproc_new(t_warrior *warr, uint32_t load_addr)
{
	t_vproc	*proc;
	int		i;

	i = 0;
	proc = NULL;
	if (!warr)
		return (NULL);
	if (!(proc = (t_vproc *)malloc(sizeof(t_vproc))))
		return (NULL);
	while (i < VM_MAX_REG_NUMBER)
	{
		proc->reg[i] = 0;
		proc->reg_bf[i] = 0;
		i++;
	}
	proc->id = 0;
	proc->inst = 0;
	proc->reg[REG_PC] = load_addr;
	proc->live = 0;
	proc->load_addr = load_addr;
	proc->wait_cycle = 0;
	proc->warr = warr;
	proc->next = NULL;
	proc->prev = NULL;
	return (proc);
}
