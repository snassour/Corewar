/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_checklabel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:53 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:53:56 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_dellabel(t_asm *data)
{
	int	i;

	i = 0;
	while (i < data->nb_arg)
	{
		if (data->label_in_arg[i] == LABEL_SET)
			ft_strdel(&(data->labels[i]));
		data->label_in_arg[i] = LABEL_NOTSET;
		++i;
	}
}

int		asm_checkvalidlabel(char *line)
{
	int	i;

	i = 0;
	while (line[i] != LABEL_CHAR && ft_strchr(LABEL_CHARS, line[i]))
		++i;
	if (i != 0 && line[i] == LABEL_CHAR)
		return (1);
	return (-1);
}

int		asm_checklabel(char *line, char *label, t_asm *data)
{
	int		ret;
	char	c;

	ret = 0;
	if (label)
		ret = asm_checkvalidlabel(line);
	if (ret < 0)
	{
		data->error_type = INVALID_LABEL;
		asm_parse_file_error(data, NULL, NULL);
		return (-1);
	}
	c = *label;
	*label = '\0';
	data->set_label = YES;
	if (asm_lablist(data, line) == -1)
	{
		*label = c;
		return (-1);
	}
	*label = c;
	return (ret);
}
