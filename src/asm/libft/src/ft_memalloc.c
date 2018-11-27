/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:31:20 by snassour          #+#    #+#             */
/*   Updated: 2015/11/27 19:23:53 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size > 0)
	{
		ptr = (void *)malloc(size);
		if (ptr)
			ft_bzero(ptr, size);
	}
	return (ptr);
}
