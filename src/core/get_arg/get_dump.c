/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:01:34 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:17:40 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_dump(t_corewar *core, int argc, char **argv, int i)
{
	if (core->dump != -1)
	{
		ft_printf_err("Error: argument %d. `-dump` has allready been ", i);
		ft_printf_err("called with parameter %d \n", core->dump);
		return (ERROR);
	}
	else if ((i + 1) == argc)
	{
		ft_printf_err("Error: argument %d. Expected parameter for ", i);
		ft_printf_err("for `-dump` flag\n");
		return (ERROR);
	}
	else if (check_number(argv[i + 1], i + 1) == ERROR)
		return (ERROR);
	else
		core->dump = ft_atoi(argv[i + 1]);
	return (i + 1);
}
