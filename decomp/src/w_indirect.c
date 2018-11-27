/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_indirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 21:31:37 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:16:49 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

int		w_indirect(uint8_t buffer[BUFF_SIZE], int *i)
{
	uint8_t			tab[4];
	short			ret;

	tab[0] = buffer[*i];
	tab[1] = buffer[*i + 1];
	(*i) += 2;
	ret = tab[0] * 256 + tab[1];
	return (ret);
}
