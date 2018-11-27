/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:24:11 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 14:00:33 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (s)
	{
		i = ft_strlen(s);
		while (s[i] != c && i)
			i--;
		if (s[i] == c)
			return ((char *)(s + i));
	}
	return (NULL);
}
