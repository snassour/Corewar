/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:53 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:53:56 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	toggle_endianess(int *n)
{
	char *tmp;
	char i;

	tmp = (char *)n;
	i = tmp[0];
	tmp[0] = tmp[3];
	tmp[3] = i;
	i = tmp[1];
	tmp[1] = tmp[2];
	tmp[2] = i;
}

int		asm_bigendian(int number, int size)
{
	if (size == 4)
		toggle_endianess(&number);
	if (size == 2)
		toggle_endianess(&number);
	if (size == 1)
		toggle_endianess(&number);
	return (number);
}

int		asm_max(int a, int b)
{
	return (a > b ? a : b);
}

int		asm_blank(char *line, int begin)
{
	int j;

	j = 0;
	while (line[begin] && (line[begin + j] == '\t' || line[begin + j] == ' '))
		++j;
	return (j);
}
