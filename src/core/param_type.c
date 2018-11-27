/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:05:30 by imhaimou          #+#    #+#             */
/*   Updated: 2018/10/07 13:05:59 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			param_type(uint8_t encoded, int param_nb)
{
	uint8_t	param;

	param = 0;
	if (param_nb == 1)
		param = (encoded >> 6);
	else if (param_nb == 2)
		param = (uint8_t)(encoded << 2) >> 6;
	else if (param_nb == 3)
		param = (uint8_t)(encoded << 4) >> 6;
	if (param == TYPE_REG)
		return (TYPE_REG);
	else if (param == TYPE_DIR)
		return (TYPE_DIR);
	else if (param == TYPE_IND)
		return (TYPE_IND);
	else
		return (0);
}
