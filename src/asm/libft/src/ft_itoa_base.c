/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:07 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 12:21:58 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char_len(int value, int base)
{
	int	len;

	len = 0;
	if (value < 0)
		value = -value;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*dest;
	int		i;

	dest = NULL;
	tab = NULL;
	if (base == 10)
		return (ft_itoa(value));
	if (base < 2 && base > 16)
		return (NULL);
	if (value < 0)
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * 17)))
		ft_strcpy(tab, "0123456789ABCDEF");
	i = ft_count_char_len(value, base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest[i + 1] = 0;
	while (i >= 0)
	{
		dest[i--] = tab[value % base];
		value = value / base;
	}
	ft_strdel(&tab);
	return (dest);
}
