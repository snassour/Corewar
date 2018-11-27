/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:21 by snassour          #+#    #+#             */
/*   Updated: 2015/11/28 17:58:27 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ret;

	ret = ft_strlen(src) + ft_strlen(dst);
	if (size >= ft_strlen(dst))
	{
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
		return (ret);
	}
	return (size + ft_strlen(src));
}
