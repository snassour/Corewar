/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_direct_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 00:07:24 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:08:56 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

int		is_direct_char(int inst, int param_n)
{
	if ((inst == 10 && (param_n == 1 || param_n == 2))
			|| (inst == 11 && (param_n == 2 || param_n == 3))
			|| (inst == 14 && (param_n == 1 || param_n == 2))
			|| (inst == 9 || inst == 12 || inst == 15))
		return (2);
	return (4);
}
