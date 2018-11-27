/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:30:44 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 19:16:46 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int argc, char **argv)
{
	t_corewar	core;

	init_core(&core);
	if (get_arg(&core, argc, argv) == ERROR)
		return (1);
	if ((core.flag & FLAG_T) != 0)
		if (init_tui(&core) == ERROR)
			return (1);
	load_warrior(&core);
	if ((core.flag & FLAG_T) != 0)
		exec_vproc_q_tui(&core);
	else
		exec_vproc_q(&core);
	shutdown_core(&core);
	return (0);
}
