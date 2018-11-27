/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piquerue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:11:27 by piquerue          #+#    #+#             */
/*   Updated: 2018/10/06 18:11:41 by piquerue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				manage_input(t_corewar *core, int c)
{
	if (c == KEY_MOUSE)
	{
		manage_mouse(core, c);
		return ;
	}
	if (c == TUI_PLAY1 || c == TUI_PLAY2 || c == TUI_PLAY3)
		core->exec_stat = togle_exec_stat(core);
	else if (c == TUI_UP1 || c == TUI_UP2 || c == TUI_UP3)
		set_exec_speed(core, core->exec_speed + SPEDD_CHANGE_FACTOR);
	else if (c == TUI_DOWN1 || c == TUI_DOWN2 || c == TUI_DOWN3)
		set_exec_speed(core, core->exec_speed - SPEDD_CHANGE_FACTOR);
	else if (c == TUI_NEXT1 || c == TUI_NEXT2 || c == TUI_NEXT3 ||
			c == TUI_NEXT4)
		exec_next(core);
}
