/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vproc_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:12:27 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:13:16 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		vproc_push(t_corewar *core, t_vproc *proc)
{
	t_vproc	*tmp;

	if (!core || !proc)
		return ;
	proc->id = core->proc_q_len;
	tmp = core->proc_q;
	core->proc_q = proc;
	core->proc_q->next = tmp;
	if (tmp)
		tmp->prev = core->proc_q;
	core->proc_q_len++;
}
