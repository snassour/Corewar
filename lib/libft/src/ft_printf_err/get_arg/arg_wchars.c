/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_wchars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:24:22 by suddin            #+#    #+#             */
/*   Updated: 2018/01/25 07:25:01 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_err.h>

wchar_t	*arg_wchars(int *read, int arg_num, t_pdata *print, va_list args)
{
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		return (va_arg(args, wchar_t *));
	}
	while (*read < print->flags)
	{
		va_arg(args, char *);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	return (va_arg(args, wchar_t *));
}
