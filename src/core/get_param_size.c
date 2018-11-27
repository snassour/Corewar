/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:01:29 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:01:52 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_param_size(uint32_t param_type)
{
	if (param_type == TYPE_REG)
		return (VM_REGISTER_SIZE);
	else if (param_type == TYPE_DIR)
		return (VM_DIR_SIZE);
	else if (param_type == TYPE_IND)
		return (VM_IND_SIZE);
	else
		return (0);
}
