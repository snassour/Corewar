/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:12:01 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:34:37 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	fill_warr(t_warrior *warr)
{
	int				fd;
	int				err;

	fd = -1;
	err = 0;
	if ((fd = open(warr->file_name, O_RDONLY)) < 0)
	{
		ft_printf_err("Error: opening file `%s`: %s.\n", warr->file_name, \
			strerror(errno));
		return (ERROR);
	}
	if (err == 0 && read_magic(warr->file_name, fd) == ERROR)
		err = 1;
	if (err == 0 && read_name(warr, warr->file_name, fd) == ERROR)
		err = 1;
	if (err == 0 && read_inst_size(warr, warr->file_name, fd) == ERROR)
		err = 1;
	if (err == 0 && read_comment(warr, warr->file_name, fd) == ERROR)
		err = 1;
	if (err == 0 && read_inst(warr, warr->file_name, fd) == ERROR)
		err = 1;
	close(fd);
	if (err == 1)
		return (ERROR);
	return (SUCCESS);
}

int					read_file(t_corewar *core)
{
	t_uint			i;

	i = 0;
	while (i < core->max_warr)
	{
		if (fill_warr(&(core->warr[i])) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
