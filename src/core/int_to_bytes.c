/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:02:29 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:03:26 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t				*int_to_bytes(uint32_t num, unsigned num_len)
{
	static uint8_t	val[8];

	ft_memset(val, 0, 8);
	if (num_len != 1 && num_len != 2 && num_len != 4)
		return (NULL);
	if (num_len == 1)
	{
		val[0] = num;
		return (val);
	}
	else if (num_len == 2)
	{
		val[0] |= num >> 8;
		val[1] |= (uint8_t)num;
		return (val);
	}
	else if (num_len == 4)
	{
		val[0] = num >> 24;
		val[1] = ((num >> 16) << 24) >> 24;
		val[2] = ((num >> 8) << 24) >> 24;
		val[3] = (num << 24) >> 24;
		return (val);
	}
	return (NULL);
}
