/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_register.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:16:25 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 19:15:28 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	copy_register(int32_t *dest, int32_t *src)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (i < VM_MAX_REG_NUMBER)
	{
		dest[i] = src[i];
		i++;
	}
}
