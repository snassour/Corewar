/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:15:09 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:14:46 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

int		opc(uint8_t *nb, uint8_t t[3])
{
	uint8_t tmp;
	uint8_t nb_bis;

	if (*nb == LIVE || *nb == ZJMP || *nb == FORK || *nb == LFORK)
	{
		t[0] = DIRECT;
		return (1);
	}
	nb_bis = *(nb + 1);
	tmp = nb_bis >> 6;
	t[0] = tmp;
	nb_bis = nb_bis << 2;
	tmp = nb_bis >> 6;
	t[1] = tmp;
	nb_bis = nb_bis << 2;
	tmp = nb_bis >> 6;
	t[2] = tmp;
	return (2);
}
