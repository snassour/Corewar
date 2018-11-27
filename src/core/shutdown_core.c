/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:10:09 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:10:39 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		shutdown_core(t_corewar *core)
{
	t_vproc	*proc;

	proc = NULL;
	if ((core->flag & FLAG_T) != 0)
		endwin();
	while (core->proc_q)
	{
		proc = core->proc_q->next;
		ft_memdel((void *)&(core->proc_q));
		core->proc_q = proc;
	}
}
