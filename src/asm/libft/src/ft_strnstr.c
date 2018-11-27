/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:54:23 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 13:58:13 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (*s2 == 0)
		return ((char *)s1);
	i = 0;
	while (*(s1 + i) && (i < n))
	{
		j = 0;
		while ((s1[i + j] == s2[j]) && s1[i + j] && ((i + j) < n))
		{
			j++;
			if (s2[j] == 0)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
