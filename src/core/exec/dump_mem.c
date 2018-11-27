/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:05:48 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:06:22 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_mem(t_corewar *core)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < VM_MEM_SIZE)
	{
		if (count == 32)
		{
			count = 0;
			ft_printf("\n");
		}
		ft_printf("0x%02hhx", core->memory[i]);
		if ((count + 1) != 32)
			ft_printf(" ", core->memory[i]);
		i++;
		count++;
	}
	ft_printf("\n");
}
