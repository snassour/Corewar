/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:52:58 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:00:34 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

int		check_instruction(uint8_t buffer[BUFF_SIZE], int tab_fd[3],
														char *argv, char *cor)
{
	if (!w_instructions(buffer, tab_fd[1], tab_fd[2] & FLAG_I, argv))
	{
		remove(cor);
		free(cor);
		return (0);
	}
	return (1);
}
