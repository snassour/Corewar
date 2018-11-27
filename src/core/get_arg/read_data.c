/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:07:32 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 21:57:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			read_magic(char *file, int fd)
{
	uint8_t	magic[4];
	int		rd;

	rd = 0;
	rd = read(fd, magic, 4);
	if (rd < 4)
	{
		ft_printf_err("Error: reading magic number, read %d/4 bytes", rd);
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	if (ft_memcmp("\x00\xea\x83\xf3", magic, 4) != 0)
	{
		ft_printf_err("Error: bad magic number in `%s`, expected ", file);
		ft_printf_err(" 00 ea 83 f3 but got %x %x %x %x\n", magic[0], magic[1],\
			magic[2], magic[3]);
		return (ERROR);
	}
	return (SUCCESS);
}

int			read_name(t_warrior *warr, char *file, int fd)
{
	int		rd;

	rd = 0;
	rd = read(fd, warr->name, VM_PROG_NAME_LENGTH);
	if (rd < VM_PROG_NAME_LENGTH)
	{
		ft_printf_err("Error: reading name, read %d/%d bytes.", rd,\
			VM_PROG_NAME_LENGTH);
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", fromn `%s`.\n", file);
		return (ERROR);
	}
	if (lseek(fd, 4, SEEK_CUR) < (VM_PROG_NAME_LENGTH + 4))
	{
		ft_printf_err("Error: setting lseek offset to next 4 ");
		ft_printf_err("bytes after reading name.");
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	return (SUCCESS);
}

int			read_inst_size(t_warrior *warr, char *file, int fd)
{
	uint8_t	inst[4];
	int		rd;

	rd = 0;
	rd = read(fd, inst, 4);
	if (rd < 4)
	{
		ft_printf_err("Error: reading instruction length,read %d/4 bytes.", rd);
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	warr->inst_len = bytes_to_int(inst, 4);
	if (warr->inst_len > VM_MAX_INST_SIZE)
	{
		ft_printf_err("Error: instruction section too big %d/", warr->inst_len);
		ft_printf_err("%d, in `%s`.\n", VM_MAX_INST_SIZE, file);
		return (ERROR);
	}
	return (SUCCESS);
}

int			read_comment(t_warrior *warr, char *file, int fd)
{
	int		rd;

	rd = 0;
	rd = read(fd, warr->comm, VM_COMMENT_LENGTH);
	if (rd < VM_COMMENT_LENGTH)
	{
		ft_printf_err("Error: reading comment, read %d/%d bytes.", rd,\
			VM_COMMENT_LENGTH);
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	if (lseek(fd, 4, SEEK_CUR) < (VM_PROG_NAME_LENGTH + 4))
	{
		ft_printf_err("Error: setting lseek offset to next ");
		ft_printf_err("4 bytes after reading comment.");
		if (errno != 0)
			ft_printf_err(" (because: %s).", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	return (SUCCESS);
}

int			read_inst(t_warrior *warr, char *file, int fd)
{
	int		rd;

	rd = 0;
	rd = read(fd, warr->inst, warr->inst_len);
	if (rd < (signed)warr->inst_len)
	{
		ft_printf_err("Error: reading instructions, read %d/%d bytes.", rd, \
			VM_COMMENT_LENGTH);
		if (errno != 0)
			ft_printf_err(" (because: %s)", strerror(errno));
		ft_printf_err(", from `%s`.\n", file);
		return (ERROR);
	}
	return (SUCCESS);
}
