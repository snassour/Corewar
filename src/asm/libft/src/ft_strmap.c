/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:45:38 by snassour          #+#    #+#             */
/*   Updated: 2015/12/01 19:20:36 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
	}
	return (str);
}
