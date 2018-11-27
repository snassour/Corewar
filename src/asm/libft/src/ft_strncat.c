/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:09:51 by snassour          #+#    #+#             */
/*   Updated: 2015/11/29 14:27:18 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 && n)
	{
		i = ft_strlen(s1);
		j = 0;
		while (*(s2 + j) && j < n)
		{
			*(s1 + i + j) = *(s2 + j);
			j++;
		}
		*(s1 + i + j) = 0;
	}
	return (s1);
}
