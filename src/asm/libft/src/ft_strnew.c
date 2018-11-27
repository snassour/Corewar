/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:55:43 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 13:39:45 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size] = 0;
		while (size > 0)
			str[--size] = 0;
	}
	return (str);
}
