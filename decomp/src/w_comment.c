/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_comment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:37:38 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:16:05 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

void	w_comment(uint8_t buffer[BUFF_SIZE], int fd)
{
	int i;

	i = 140;
	write(fd, ".comment \"", 10);
	while (i < 2192 && buffer[i])
		write(fd, &buffer[i++], 1);
	write(fd, "\"\n\n", 3);
}
