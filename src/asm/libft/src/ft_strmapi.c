/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:12:06 by snassour          #+#    #+#             */
/*   Updated: 2015/12/01 19:23:03 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
	}
	return (str);
}
