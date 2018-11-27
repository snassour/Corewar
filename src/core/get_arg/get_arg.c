/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:54:26 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/09 00:07:42 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			get_arg1(t_corewar *core, int argc, char **argv, int *i)
{
	if (ft_strcmp(argv[*i], "-n") == 0)
	{
		*i = get_n(core, argc, argv, *i);
		if (*i == ERROR)
			return (ERROR);
	}
	else if (ft_strcmp(argv[*i], "-dump") == 0)
	{
		*i = get_dump(core, argc, argv, *i);
		if (*i == ERROR)
			return (ERROR);
	}
	else if (ft_strcmp(argv[*i], "-t") == 0 \
			|| ft_strcmp(argv[*i], "--tui") == 0)
		core->flag |= FLAG_T;
	else if (set_warr_file(core, argv[*i], 0) == ERR)
		return (ERROR);
	return (SUCCESS);
}

int					get_arg(t_corewar *core, int argc, char **argv)
{
	int				i;

	i = 0;
	if (argc < 2)
	{
		ft_printf_err("Error: No argument passed\n\n");
		ft_printf_err("usage: ./corewar [OPTIONS] [warrior(s)]\n\tOptions:\n");
		ft_printf_err("\t -dump <num> : Dump memory after <num> cycle\n");
		ft_printf_err("\t -t, --tui   : Open a visualizer \n");
		return (ERROR);
	}
	while (++i < argc)
	{
		if (get_arg1(core, argc, argv, &i) == ERROR)
			return (ERROR);
	}
	set_warr_nb(core);
	if (core->max_warr <= 0)
	{
		ft_printf_err("iError: Need at least one warrior.\n");
		return (ERROR);
	}
	if (read_file(core) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
