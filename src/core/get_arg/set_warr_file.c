/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_warr_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:09:57 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 12:10:18 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		set_warr_file(t_corewar *core, char *file, int warr_nb)
{
	if (core->max_warr == 4)
	{
		ft_printf_err("Error: Too many warriors given. ");
		ft_printf_err("Maximum 4 warriors excepted.\n");
		return (ERROR);
	}
	core->warr[core->max_warr].warr_nb = warr_nb;
	core->warr[core->max_warr].file_name = file;
	core->max_warr++;
	return (SUCCESS);
}
