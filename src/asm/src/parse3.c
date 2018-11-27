/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 05:25:25 by snassour          #+#    #+#             */
/*   Updated: 2018/10/21 19:25:08 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_parse_file_error(t_asm *data, char **line, char **nc)
{
	ft_strdel(nc);
	ft_strdel(line);
	close(data->fd);
	get_next_line(data->fd, line);
	asm_error(data->error_type, NULL, data);
	return (-1);
}

int		asm_close_error(t_asm *data)
{
	close(data->fd);
	return (-1);
}

int		asm_extend3_header(t_asm *d, char **str, int var[5])
{
	char	*tmp;

	++var[3];
	var[4] += (var[1] == ' ' || var[1] == '\n' || var[1] == '\t') ? 1 : 0;
	++var[2];
	d->error_type = MFAIL;
	if ((tmp = realloc(*str, var[2] + 1)) == NULL)
		return (asm_parse_file_error(d, str, NULL));
	*str = tmp;
	(*str)[var[2] - 1] = var[1];
	(*str)[var[2]] = '\0';
	d->error_type = d->name == 0 ? CHAMPION_NAME_ERROR : COMMENT_ERROR;
	return (1);
}

int		asm_extend4_header(t_asm *d, char **str, int var[5])
{
	ft_strdel(str);
	if ((var[3] == var[4] || var[0] == -1 || d->name == 0 || d->comment == 0))
		return (asm_error_header(d, var[3], var[4], var[0]));
	return (1);
}

int		asm_header_2(t_asm *d)
{
	int		v[5];
	char	*str;

	str = NULL;
	ft_bzero(v, sizeof(int) * 5);
	while ((!d->name || !d->comment) && (v[0] = read(d->fd, &v[1], 1)) > 0)
	{
		if (asm_extend3_header(d, &str, v) == -1)
			return (-1);
		if ((v[0] = asm_extend1_header(d, &str, (char *)&(v[1]), &v[2])) != 2)
		{
			if (v[0] == 0)
				break ;
			else if (v[0] == -1)
				return (-1);
		}
		else if ((v[0] = asm_extend2_header(d, &str, &v[2])) != 2)
		{
			if (v[0] == -1)
				return (v[0]);
			else if (v[0] == 0)
				continue ;
		}
	}
	return (asm_extend4_header(d, &str, v));
}
