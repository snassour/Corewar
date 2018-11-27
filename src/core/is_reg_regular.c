/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg_regular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:03:33 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:03:51 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_reg_regular(int8_t reg)
{
	if (reg >= 1 && reg <= VM_REG_NUMBER)
		return (SUCCESS);
	return (ERROR);
}
