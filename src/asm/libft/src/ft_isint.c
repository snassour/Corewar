/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:00:49 by snassour          #+#    #+#             */
/*   Updated: 2016/10/17 16:37:37 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int		i;
	char	*num;

	if (!str || !*str)
		return (FALSE);
	i = str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] != 0)
		return (FALSE);
	i = ft_atoi(str);
	if (i == 0 && ft_strcmp(str, "-0") == 0)
		return (TRUE);
	num = ft_itoa(i);
	if (num)
		i = ft_strcmp(num, str);
	ft_strdel(&num);
	return (i == 0 ? TRUE : FALSE);
}

int	ft_isnum(char *str)
{
	int		i;
	char	*num;

	if (!str || !*str)
		return (FALSE);
	i = 0;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] != 0)
		return (FALSE);
	i = ft_atoi(str);
	num = ft_itoa(i);
	if (num)
		i = ft_strcmp(num, str);
	ft_strdel(&num);
	return (i == 0 ? TRUE : FALSE);
}
