/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 05:25:10 by snassour          #+#    #+#             */
/*   Updated: 2018/10/19 05:25:13 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_strdel(char **str)
{
	if (str)
		if (*str)
		{
			free(*str);
			str = NULL;
		}
	return (0);
}

int		asm_set_name_comment(t_asm *d, int j, int l, int type)
{
	int		m;

	d->name = (type == 1 ? 1 : d->name);
	d->comment = (type == 2 ? 1 : d->comment);
	m = (type == 1 ? PROG_NAME_LENGTH : COMMENT_LENGTH);
	m = (j - l - 1 > m ? m : j - l - 1);
	if (l < j - 1 && type == 1)
		ft_strncpy(d->header->prog_name, d->str + l + 1, m);
	else if (l < j - 1 && type == 2)
		ft_strncpy(d->header->comment, d->str + l + 1, m);
	ft_strdel(&(d->str));
	return (1);
}

int		asm_realloc(t_asm *d, char **str, int size)
{
	char	*tmp;

	d->error_type = MFAIL;
	if ((tmp = realloc(*str, size)) == NULL)
		return (asm_parse_file_error(d, str, NULL));
	*str = tmp;
	return (1);
}

int		asm_get_name_comment(t_asm *d, int r[4], int type)
{
	char	buf[1];

	r[3] = -1;
	while ((r[3] = read(d->fd, buf, 1)) > 0 && ++r[1])
	{
		if (asm_realloc(d, &(d->str), r[1]) == -1)
			return (-1);
		d->str[r[1] - 2] = buf[0];
		d->str[r[1] - 1] = '\0';
		if (d->str[r[0]] == '\0')
			break ;
		d->line_error += (d->str[r[0]] == '\n' ? 1 : 0);
		if ((d->str[r[0]] == '\t' || d->str[r[0]] == ' ') \
		|| (r[2] == 0 && d->str[r[0]] == '"'))
			r[2] = (r[2] == 0 && d->str[r[0]] == '"' ? r[0] : r[2]);
		else if (r[2] == 0 && d->str[r[0]] != '"')
		{
			ft_strdel(&(d->str));
			return (-1);
		}
		else if (r[2] != 0 && r[2] <= r[0] - 1 && d->str[r[0]] == '"')
			return (asm_set_name_comment(d, r[0], r[2], type));
		++r[0];
	}
	return (r[3]);
}

int		asm_search_name_comment(t_asm *d, int type)
{
	int		ret[4];

	ret[0] = 0;
	ret[1] = 1;
	ret[2] = 0;
	ret[3] = asm_get_name_comment(d, ret, type);
	ft_strdel(&(d->str));
	if (ret[3] == -1 || ret[3] == 0)
	{
		if (ret[3] == 0 && d->name == 0)
			d->error_type = CHAMPION_NAME_ERROR;
		else if (ret[3] == 0 && d->comment == 0)
			d->error_type = COMMENT_ERROR;
		else
			d->error_type = FILE_NO_OPEN;
	}
	return ((ret[3] == -1 || ret[3] == 0) ? -1 : 1);
}
