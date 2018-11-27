/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_warr_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:10:24 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 12:11:04 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static inline int	exist_warr_nb(t_corewar *core, int nb)
{
	t_uint			i;

	i = 0;
	while (i < core->max_warr)
	{
		if (core->warr[i].warr_nb == nb)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int					set_warr_nb(t_corewar *core)
{
	int				nb;
	t_uint			i;

	i = 0;
	while (i < core->max_warr)
	{
		if (core->warr[i].warr_nb == 0)
		{
			nb = 1;
			while (exist_warr_nb(core, nb) == ERROR)
				nb++;
			core->warr[i].warr_nb = nb;
		}
		i++;
	}
	return (SUCCESS);
}
