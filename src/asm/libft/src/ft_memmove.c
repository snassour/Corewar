/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:48:16 by snassour          #+#    #+#             */
/*   Updated: 2015/11/29 18:33:22 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (len > 0)
	{
		if (dst < src)
			while (i < len)
			{
				*(char *)(dst + i) = *(char *)(src + i);
				i++;
			}
		if (i != len)
			while (len-- > 0)
				*((char *)(dst + len)) = *((char *)(src + len));
	}
	return (dst);
}
