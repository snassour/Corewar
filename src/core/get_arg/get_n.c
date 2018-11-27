/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:06:48 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 21:25:53 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	check_warr_nb(t_corewar *core, int arg_nb, int nb)
{
	t_uint			i;

	i = 0;
	while (i < core->max_warr)
	{
		if (core->warr[i].warr_nb == nb)
		{
			ft_printf_err("Error: argument %d. ", arg_nb);
			ft_printf_err("Number allready assigned\n");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int					get_n(t_corewar *core, int argc, char **argv, int i)
{
	int nb;

	nb = 0;
	if ((i + 1) == argc)
	{
		ft_printf_err("Error: argument %d. ", i);
		ft_printf_err("Expected parameter for `-n` flag\n");
		return (ERROR);
	}
	if (check_number(argv[i + 1], i + 1) == ERROR)
		return (ERROR);
	nb = ft_atoi(argv[i + 1]);
	if (check_warr_nb(core, i + 1, nb) == ERROR)
		return (ERROR);
	else
		core->warr[core->max_warr].warr_nb = nb;
	if ((i + 2) == argc)
	{
		ft_printf_err("Error: argument %d. ", i);
		ft_printf_err("Expected file name for `-n` flag\n");
		return (ERROR);
	}
	if (set_warr_file(core, argv[i + 2], nb) == ERROR)
		return (ERROR);
	return (i + 2);
}
