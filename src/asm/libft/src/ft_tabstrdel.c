/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:17:38 by snassour          #+#    #+#             */
/*   Updated: 2016/10/17 15:40:58 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrdel(char ***str, size_t len)
{
	size_t i;

	i = 0;
	if (str)
	{
		if (*str)
		{
			while (i < len)
				ft_strdel((*str) + i++);
			free(*str);
			*str = NULL;
		}
	}
}
