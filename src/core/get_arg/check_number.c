/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:53:11 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:17:31 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_num(int arg_nb)
{
	ft_printf_err("Error: argument %d is expected with no sign\n", arg_nb);
	return (ERROR);
}

static int		check_num1(char *str, int arg_nb)
{
	if (str[0] == '+' || str[0] == '-')
		return (check_num(arg_nb));
	return (SUCCESS);
}

int				check_number(char *str, int arg_nb)
{
	int			i;

	if (!str)
		return (ERROR);
	i = -1;
	if (check_num1(str, arg_nb) == ERROR)
		return (ERROR);
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf_err("Error: argument %d. Expected only numbers\n",\
				arg_nb);
			return (ERROR);
		}
	}
	if (i == 0)
		return (check_num(arg_nb));
	if (i > 13 || ft_atol(str) > INT_MAX)
		return (check_num(arg_nb));
	return (SUCCESS);
}
