/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:23:52 by snassour          #+#    #+#             */
/*   Updated: 2015/12/01 20:02:43 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		l;
	size_t	len;

	i = 0;
	str = NULL;
	if (s)
	{
		len = ft_strlen(s);
		l = len - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while (l >= 0 && (s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && l > i)
			l--;
		str = ft_strsub(s, (size_t)i, (size_t)l - (size_t)i + 1);
	}
	return (str);
}
