/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:04:22 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/22 22:09:26 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

int		check_magic(uint8_t t[BUFF_SIZE])
{
	if (t[0] != (unsigned char)0 || t[1] != (unsigned char)234 ||
			t[2] != (unsigned char)131 || t[3] != (unsigned char)243)
		return (0);
	return (1);
}
