/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 00:03:38 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:03:37 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

void	ft_printc(int fd, char *str, ...)
{
	va_list	lst;
	char	*tmp;

	va_start(lst, str);
	while (*str)
		if (*str == '%' && *(str + 1) == 's' && (str += 2))
		{
			tmp = va_arg(lst, char*);
			write(fd, tmp, ft_strlen(tmp));
		}
		else if (*str == '%' && *(str + 1) == 'd' && (str += 2))
		{
			tmp = ft_itoa(va_arg(lst, int));
			write(fd, tmp, ft_strlen(tmp));
			free(tmp);
		}
		else if (*str == '%' && *(str + 1) == 'c' && (str += 2))
		{
			tmp = ft_itoa(va_arg(lst, int));
			write(fd, tmp, ft_strlen(tmp));
			free(tmp);
		}
		else
			write(fd, str++, 1);
	va_end(lst);
}
