/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:50:29 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 18:04:49 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					check_delay(t_corewar *core)
{
	struct timespec	tm;

	tm.tv_sec = 0;
	tm.tv_nsec = 0;
	if (!core)
		return (SUCCESS);
	clock_gettime(CLOCK_MONOTONIC_RAW, &tm);
	if (tm.tv_sec > core->exec_wait_time.tv_sec)
		return (SUCCESS);
	else if (tm.tv_sec >= core->exec_wait_time.tv_sec)
		if (tm.tv_nsec >= core->exec_wait_time.tv_nsec)
			return (SUCCESS);
	return (ERROR);
}

void				set_delay(t_corewar *core)
{
	int				sec;
	int				nsec;
	double			factor;

	sec = 0;
	nsec = 0;
	factor = 0.0;
	if (!core)
		return ;
	clock_gettime(CLOCK_MONOTONIC_RAW, &(core->exec_set_time));
	factor = (100 - (core->exec_speed)) * (long double)SPEED_FACTOR;
	sec = (int)factor;
	nsec = 10000000000 * (factor - sec);
	core->exec_wait_time.tv_sec = core->exec_set_time.tv_sec + sec;
	core->exec_wait_time.tv_nsec = core->exec_set_time.tv_nsec + nsec;
	(void)factor;
}
