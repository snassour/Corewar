/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:32:41 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 13:21:38 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest)
		dest = ft_memcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
