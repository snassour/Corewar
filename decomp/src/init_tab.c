/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:02:39 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/25 00:35:37 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

void	init_tab(const char *t[16])
{
	t[0] = "live  ";
	t[1] = "ld    ";
	t[2] = "st    ";
	t[3] = "add   ";
	t[4] = "sub   ";
	t[5] = "and   ";
	t[6] = "or    ";
	t[7] = "xor   ";
	t[8] = "zjmp  ";
	t[9] = "ldi   ";
	t[10] = "sti   ";
	t[11] = "fork  ";
	t[12] = "lld   ";
	t[13] = "lldi  ";
	t[14] = "lfork ";
	t[15] = "aff   ";
}
