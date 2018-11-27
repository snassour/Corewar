/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:15:19 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 12:16:14 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t		bytes_to_int(const uint8_t *num, unsigned num_len)
{
	int32_t	val;

	val = 0;
	if (!num || (num_len != 1 && num_len != 2 && num_len != 4))
		return (ERROR);
	if (num_len == 1)
		return ((int8_t)num[0]);
	else if (num_len == 2)
	{
		val |= (uint32_t)num[0] << 8;
		val |= (uint32_t)num[1];
		return ((int16_t)val);
	}
	else if (num_len == 4)
	{
		val |= (uint32_t)num[0] << 24;
		val |= (uint32_t)num[1] << 16;
		val |= (uint32_t)num[2] << 8;
		val |= (uint32_t)num[3];
		return ((int32_t)val);
	}
	return (ERROR);
}
