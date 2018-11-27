/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:11:53 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:12:02 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				exec_next(t_corewar *core)
{
	if (core->exec_stat == STAT_PLAY)
		core->pause = 1;
	else
	{
		core->exec_stat = STAT_PLAY;
		core->pause = 1;
	}
}
