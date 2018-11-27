/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:52:35 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:52:38 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_write_color(char *color, int len, int output)
{
	if (color == NULL)
		return ;
	if (isatty(output) == 1)
		write(output, color, len);
}
