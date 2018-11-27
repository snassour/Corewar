/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:13:22 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:13:35 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t				*read_mem(t_corewar *core, int location)
{
	int				i;
	static uint8_t	data[VM_MAX_READ_MEM];

	if (location < 0)
	{
		location = location % VM_MEM_SIZE;
		location *= -1;
		location = VM_MEM_SIZE - location;
	}
	ft_memset(data, 0, VM_MAX_READ_MEM);
	i = 0;
	while (i < VM_MAX_READ_MEM)
	{
		if (location >= VM_MEM_SIZE)
			location = location % VM_MEM_SIZE;
		data[i] = core->memory[location];
		location++;
		i++;
	}
	return (data);
}
