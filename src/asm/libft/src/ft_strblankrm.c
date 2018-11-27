/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimxtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:45:04 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 17:17:27 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** "for atoi advanced" i.e. :-	1 000 000 -> -1000000
*/

static	size_t	ft_count_char_len(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_isblank(s[i]))
			j++;
		i++;
	}
	return (j);
}

char			*ft_strblankrm(char const *s)
{
	char	*str;
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	l = 0;
	j = 0;
	str = NULL;
	if (s)
	{
		i = ft_count_char_len(s);
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (str)
		{
			while (s[l])
			{
				while (ft_isblank(s[l]) && s[l])
					l++;
				str[j++] = s[l++];
			}
			str[j] = 0;
		}
	}
	return (str);
}
