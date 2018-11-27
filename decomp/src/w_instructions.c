/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:03:08 by cbrian            #+#    #+#             */
/*   Updated: 2018/10/24 10:47:09 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

static int				nb_arg_op(char op)
{
	if (op == 1 || op == 9 || op == 12 || op == 15 || op == 16)
		return (1);
	if (op == 2 || op == 3 || op == 13)
		return (2);
	else
		return (3);
}

static int				error(uint8_t buffer, char *argv)
{
	if (buffer < 1 || buffer > 16)
	{
		ft_printf_err("Error : wrong instructions in %s\n", argv);
		return (0);
	}
	return (1);
}

static void				init(int nb[4], uint8_t buffer[BUFF_SIZE],
																uint8_t tab[3])
{
	nb[2] = buffer[nb[0]];
	nb[1] = nb_arg_op(buffer[nb[0]]);
	nb[0] += opc(&buffer[nb[0]], tab);
	nb[3] = 0;
}

static void				check_end(int nb[4], int fd, int adr, int o)
{
	if (++nb[3] < nb[1])
		write(fd, ", ", 2);
	else
	{
		if (o != FLAG_I)
			write(fd, "\n", 1);
		else
		{
			ft_putstr_fd(" #", fd);
			ft_putnbr_fd(adr - nb[3] - 1, fd);
			write(fd, "\n", 1);
		}
	}
}

/*
**with nb[0] = index for buffer;
**     nb[1] = nb argument for instruction
**     nb[2] = 1 or 0 (if arg direct is on 2 or 4 bytes)
**     nb[3] = k (index nb arg)
**with tab[3] = opc in binary
**with t[16] = instructions name
**with o = option -i
*/

int						w_instructions(uint8_t buffer[BUFF_SIZE], int fd, int o,
																	char *argv)
{
	int					nb[4];
	uint8_t				tab[3];
	const char			*t[16];
	int					adr;

	nb[0] = 2192;
	adr = 0;
	init_tab(t);
	while (buffer[nb[0]])
	{
		adr++;
		if (!error(buffer[nb[0]], argv))
			return (0);
		write(fd, t[buffer[nb[0]] - 1], 6);
		init(nb, buffer, tab);
		while (nb[3] < nb[1])
		{
			adr++;
			w_arg(tab, nb, buffer, fd);
			check_end(nb, fd, adr, o);
		}
	}
	return (1);
}
