/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:16:07 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:17:02 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					write_mem(t_warrior *warr, int location, uint8_t *src,
		t_uint src_len)
{
	t_uint			i;
	int				flag;
	uint8_t			*memory;

	if (!warr || !src || src_len == 0)
		return (ERROR);
	if (location < 0)
	{
		location = location % VM_MEM_SIZE;
		location *= -1;
		location = VM_MEM_SIZE - location;
	}
	i = -1;
	flag = *(warr->flag);
	memory = warr->mem_share;
	while (++i < src_len)
	{
		if (location >= VM_MEM_SIZE)
			location = location % VM_MEM_SIZE;
		memory[location] = src[i];
		if ((flag & FLAG_T) != 0)
			tui_write_mem_nor(warr, location, memory[location]);
		location++;
	}
	return (SUCCESS);
}
