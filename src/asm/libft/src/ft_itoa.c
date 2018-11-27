/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:36:23 by snassour          #+#    #+#             */
/*   Updated: 2016/10/15 15:03:07 by hlequien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(int value)
{
	int len;

	len = 1;
	if (value < 0)
		value = -value + (len++ * 0);
	while (value >= 10)
		value = value / 10 + (len++ * 0);
	return (len);
}

char		*ft_itoa(int n)
{
	char	*dest;
	int		i;

	dest = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count_len(n);
	dest = ft_strnew(i);
	if (dest == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
	}
	while (--i >= 0 && dest[i] != '-')
	{
		dest[i] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
