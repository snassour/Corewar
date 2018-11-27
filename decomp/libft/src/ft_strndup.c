/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:25:40 by suddin            #+#    #+#             */
/*   Updated: 2018/10/24 11:57:00 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t n)
{
	char *dest;

	if (!str || n == 0)
		return (NULL);
	if (!(dest = ft_strnew(n + 1)))
		return (NULL);
	ft_strncpy(dest, str, n);
	return (dest);
}
