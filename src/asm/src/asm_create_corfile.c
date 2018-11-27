/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_crete_corfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:52:03 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:52:08 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_write_corfile(t_asm *data, int fd, int j)
{
	t_clst	*tmp;
	char	*t;

	tmp = data->begin;
	while (tmp)
	{
		tmp->opcode += 1;
		write(fd, (char *)&(tmp->opcode), 1);
		if (data->op_tab[tmp->opcode - 1].ocp == 1)
			write(fd, (char *)&(tmp->ocparam), 1);
		j = -1;
		while (++j < data->op_tab[tmp->opcode - 1].n_arg)
		{
			t = (char *)&(tmp->arg[j]);
			if (tmp->arg_len[j] == 2)
			{
				t[0] = t[2];
				t[1] = t[3];
				t[2] = 0;
				t[3] = 0;
			}
			write(fd, t, tmp->arg_len[j]);
		}
		tmp = tmp->next;
	}
}

int		asm_generate_corfile(t_asm *data, int i)
{
	char	*tab;
	int		j;
	int		fd;

	tab = NULL;
	if (!(tab = ft_strnew((i + 4))))
	{
		asm_error(MFAIL, NULL, data);
		return (-1);
	}
	j = -1;
	while (++j < i - 1)
		tab[j] = data->dot_s_name[j];
	ft_strncpy(tab + j, "cor", 3);
	if ((fd = open(tab, O_CREAT | O_WRONLY, 0600)) == -1)
	{
		asm_error(ERR_CREATE_FILE, tab, data);
		return (-1);
	}
	write(fd, data->header, sizeof(t_header));
	asm_write_corfile(data, fd, 0);
	close(fd);
	ft_strdel(&tab);
	return (1);
}
