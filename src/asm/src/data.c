/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:13 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:53:16 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_reinit_data(t_asm **data)
{
	ft_bzero((*data)->arg, sizeof(int) * 3);
	ft_bzero((*data)->arg_type, sizeof(int) * 3);
	ft_bzero((*data)->arg_len, sizeof(int) * 3);
	ft_bzero((*data)->label_in_arg, sizeof(int) * 3);
	(*data)->cmd = 0;
	(*data)->nb_arg = 0;
	(*data)->set_label = 0;
	(*data)->get_label = 0;
	ft_strdel(&((*data)->labels[0]));
	ft_strdel(&((*data)->labels[1]));
	ft_strdel(&((*data)->labels[2]));
}

t_asm	*asm_init_data(void)
{
	t_asm	*data;

	data = NULL;
	if (!(data = ft_memalloc(sizeof(t_asm))))
		return (NULL);
	data->header = NULL;
	data->header = (t_header *)ft_memalloc(sizeof(t_header));
	if (!(data->header))
	{
		asm_destroy_data(&data);
		return (NULL);
	}
	ft_bzero(data->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(data->header->comment, COMMENT_LENGTH + 1);
	ft_bzero(data->arg_len, sizeof(int) * 3);
	ft_bzero(data->arg_type, sizeof(int) * 3);
	ft_bzero(data->arg, sizeof(int) * 3);
	data->str = NULL;
	data->lname = ft_strlen(NAME_CMD_STRING);
	data->lcom = ft_strlen(COMMENT_CMD_STRING);
	asm_get_optab(data);
	data->begin = NULL;
	data->lablist = NULL;
	return (data);
}

int		asm_destroy_data(t_asm **data)
{
	if (data)
		if (*data)
		{
			asm_reinit_data(data);
			ft_strdel(&((*data)->str));
			if ((*data)->lablist)
				asm_destroy_lablist(*data);
			ft_memdel((void **)&((*data)->header));
			ft_memdel((void **)data);
		}
	return (0);
}
