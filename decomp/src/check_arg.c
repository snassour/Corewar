/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 16:12:21 by cbrian            #+#    #+#             */
/*   Updated: 2018/10/24 12:02:20 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

static int			check_bin(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (len > 4 && argv[len - 1] == 'r' && argv[len - 2] == 'o' &&
			argv[len - 3] == 'c' && argv[len - 4] == '.')
		return (1);
	ft_printf_err("Error : expected a .cor file\n");
	return (0);
}

int					check_arg(int argc, char **argv, int *opt, int *k)
{
	int		i;

	*opt = 0;
	i = 1;
	while (argv[i] && (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-i"))
			&& i <= 2)
	{
		if (argv[i][0] == '-' && argv[i][1] == 'v' && !argv[i][2])
			*opt = (*opt | FLAG_V);
		else
			*opt = (*opt | FLAG_I);
		i++;
	}
	if (i == argc)
	{
		ft_printf_err("Usage : %s [option] [file.cor ...]\n", argv[0]);
		ft_printf_err("Options :\n\t-v : Verbose mode\n\t-i ");
		ft_printf_err(": Write address of instructions in file file_deasm.s\n");
		return (0);
	}
	*k = i - 1;
	while (argv[i])
		if (!check_bin(argv[i++]) || argc == 1)
			return (0);
	return (1);
}
