/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:52:58 by cbrian            #+#    #+#             */
/*   Updated: 2018/10/24 12:01:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

static int		check(char *argv, int t[3])
{
	if ((t[0] = open(argv, O_RDONLY)) == -1)
	{
		ft_printf_err("Error : opening %s. %s\n", argv, strerror(errno));
		return (0);
	}
	return (1);
}

static int		check_1(uint8_t buffer[BUFF_SIZE], int t[3], char *cor,
																	char *argv)
{
	int rd;

	if ((rd = read(t[0], buffer, BUFF_SIZE)) < 0)
	{
		ft_printf_err("Error : reading %s. %s\n", argv, strerror(errno));
		free(cor);
		return (0);
	}
	buffer[rd] = '\0';
	if (!rd || !check_magic(buffer))
	{
		!rd ? ft_printf_err("Error : Empty file for %s\n", argv) :
		ft_printf_err("Error : wrong magic number for %s\n", argv);
		free(cor);
		return (0);
	}
	if ((t[1] = open(cor, O_WRONLY | O_CREAT, S_IRWXO | S_IRWXU)) == -1)
	{
		ft_printf_err("Error : opening %s. %s\n", cor, strerror(errno));
		remove(cor);
		free(cor);
		return (0);
	}
	return (1);
}

static int		check_2(int tab_fd[3], char *argv, char *cor)
{
	if (close(tab_fd[0]) == -1)
	{
		ft_printf_err("Error : closing %s. %s\n", argv, strerror(errno));
		remove(cor);
		free(cor);
		return (0);
	}
	return (1);
}

static int		check_3(int tab_fd[3], int opt, char *cor)
{
	if (close(tab_fd[1]) == -1)
	{
		ft_printf_err("Error : closing %s. %s\n", cor, strerror(errno));
		remove(cor);
		free(cor);
		return (0);
	}
	if (opt == 1)
		ft_printf("deasm : created file \'%s\'\n", cor);
	free(cor);
	return (1);
}

/*
**with tab_fd[0] = fd of argv[i] file
**     tab_fd[1] = fd of deasm file
**     tab_fd[2] = option -v (FLAG_V) or/and -i (FLAG_I)
*/

int				main(int argc, char **argv)
{
	int			i;
	int			tab_fd[3];
	uint8_t		buffer[BUFF_SIZE + 1];
	char		*cor;

	i = 0;
	if (!check_arg(argc, argv, &tab_fd[2], &i))
		return (1);
	while (argv[++i])
	{
		if (!check(argv[i], tab_fd))
			return (1);
		created_file(argv[i], &cor);
		if (!check_1(buffer, tab_fd, cor, argv[i]))
			return (1);
		if (!check_2(tab_fd, argv[i], cor))
			return (1);
		w_name(buffer, tab_fd[1]);
		w_comment(buffer, tab_fd[1]);
		if (!check_instruction(buffer, tab_fd, argv[i], cor))
			return (1);
		if (!check_3(tab_fd, tab_fd[2] & FLAG_V, cor))
			return (1);
	}
	return (0);
}
