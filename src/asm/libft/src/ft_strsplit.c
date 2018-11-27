/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:46:30 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 14:02:30 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s)
		while (s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i] != c && s[i])
				k++;
			while (s[i] != c && s[i])
				i++;
		}
	return (k);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	nbw;
	size_t	k;
	size_t	prev;
	size_t	len;

	str = NULL;
	nbw = nb_words(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (nbw + 1));
	k = 0;
	prev = 0;
	if (s)
	{
		if (str)
			while (k < nbw)
			{
				while (s[prev] == c && s[prev])
					prev++;
				len = ft_word_len(s + prev, c);
				str[k++] = ft_strsub(s, prev, len);
				prev += len;
			}
		str[nbw] = 0;
	}
	return (str);
}
