/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:02:57 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:11:22 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		manage_mouse0(t_corewar *core, MEVENT event)
{
	if (event.bstate & SCROLL_DOWN_BTN)
		set_exec_speed(core, core->exec_speed - SPEDD_CHANGE_FACTOR);
	else if (event.bstate & SCROLL_UP_BTN)
		set_exec_speed(core, core->exec_speed + SPEDD_CHANGE_FACTOR);
}

static void		manage_mouse2(t_corewar *core, MEVENT event)
{
	if (event.bstate & BUTTON1_PRESSED)
		set_exec_speed(core, core->exec_speed + SPEDD_CHANGE_FACTOR);
}

void			manage_mouse(t_corewar *core, int c)
{
	MEVENT		event;

	if (getmouse(&event) != OK)
		return ;
	if (wenclose(core->tui.stat, event.y, event.x) == true)
	{
		if (event.bstate & BUTTON1_PRESSED)
			togle_exec_stat(core);
	}
	else if (wenclose(core->tui.high, event.y, event.x) == true)
		manage_mouse2(core, event);
	else if (wenclose(core->tui.low, event.y, event.x) == true)
	{
		if (event.bstate & BUTTON1_PRESSED)
			set_exec_speed(core, core->exec_speed - SPEDD_CHANGE_FACTOR);
	}
	else if (wenclose(core->tui.speed, event.y, event.x) == true)
		manage_mouse0(core, event);
	else if (wenclose(core->tui.next, event.y, event.x) == true)
	{
		if (event.bstate & BUTTON1_PRESSED)
			exec_next(core);
	}
	(void)c;
}
