/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_argument_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:52:09 by snassour          #+#    #+#             */
/*   Updated: 2018/10/13 17:52:11 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_error_format_argument_type(int err, t_asm *data)
{
	ft_putstr_fd(" : invalid argument type, expected types are : arg[", 2);
	ft_putnbr_fd(data->curr_arg + 1, 2);
	ft_putstr_fd("] : ", 2);
	if (err == INV_TYPE_R)
	{
		ft_putstr_fd("REGISTRE (r1 to r", 2);
		ft_putnbr_fd(REG_NUMBER, 2);
		ft_putstr_fd(")", 2);
	}
	if (err == INV_TYPE_RDI || err == INV_TYPE_RD
	|| err == INV_TYPE_RI)
	{
		ft_putstr_fd("REGISTRE (from r1 to r", 2);
		ft_putnbr_fd(REG_NUMBER, 2);
		ft_putstr_fd(") | ", 2);
	}
	if (err == INV_TYPE_D || err == INV_TYPE_RD)
		ft_putstr_fd("DIRECT expected %(INT number)", 2);
	if (err == INV_TYPE_DI || err == INV_TYPE_RDI)
		ft_putstr_fd("DIRECT expected %(INT number) | ", 2);
	if (err == INV_TYPE_I || err == INV_TYPE_DI
	|| err == INV_TYPE_RI || err == INV_TYPE_RDI)
		ft_putstr_fd("INDIRECT expected INT number", 2);
	ft_putstr_fd("\n\t\t", 2);
}

void	asm_error_format_argument(int err, t_asm *data)
{
	if (err == INVALID_ARGUMENT)
		ft_putstr_fd(" : invalid arguments\n\t\t", 2);
	else if (err == INVALID_ARG_NUM)
	{
		ft_putstr_fd(" : invalid argument number, expected number is : ", 2);
		ft_putnbr_fd(data->op_tab[data->cmd].n_arg, 2);
		ft_putstr_fd("\n\t\t", 2);
	}
	else
		asm_error_format_argument_type(err, data);
}
