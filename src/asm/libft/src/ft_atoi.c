/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:43:00 by snassour          #+#    #+#             */
/*   Updated: 2015/12/01 18:55:15 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		out;
	int		i;
	int		negative;

	i = 0;
	out = 0;
	negative = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
					str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		negative = i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
		out = out * 10 + (str[i++] - '0');
	if (str[negative] == '-')
		out = -out;
	return (out);
}
