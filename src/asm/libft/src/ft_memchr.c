/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:57:50 by snassour          #+#    #+#             */
/*   Updated: 2015/11/29 18:33:56 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (i < n && *((unsigned char *)(s + i)) != (unsigned char)c)
			i++;
		if (i == n)
			return (NULL);
	}
	return (((unsigned char *)s + i));
}
