/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 05:25:17 by snassour          #+#    #+#             */
/*   Updated: 2018/10/19 05:25:21 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_search_end_comment(t_asm *data)
{
	int		ret;
	char	buf[1];

	while ((ret = read(data->fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
		{
			data->line_error++;
			return (0);
		}
	}
	if (ret == -1)
	{
		data->error_type = FILE_NO_OPEN;
		return (-1);
	}
	return (0);
}

int		asm_check_comment_name(t_asm *data, char buf[1], int type)
{
	int	ret;

	data->error_type = (type == 1 ? CHAMPION_NAME_ERROR : COMMENT_ERROR);
	if ((type == 1 && data->name == 1) || (type == 2 && data->comment == 1))
		return (asm_parse_file_error(data, NULL, NULL));
	if (asm_search_name_comment(data, type) == -1)
		return (asm_parse_file_error(data, NULL, NULL));
	data->name = (type == 1 ? 1 : data->name);
	data->comment = (type == 2 ? 1 : data->comment);
	while ((ret = read(data->fd, buf, 1)) > 0 && buf[0] != '\n')
		if (buf[0] == COMMENT_CHAR || buf[0] == END_COMMENT_CHAR)
		{
			if (asm_search_end_comment(data) == -1)
				return (asm_parse_file_error(data, NULL, NULL));
			break ;
		}
		else if (buf[0] != ' ' && buf[0] != '\t' \
		&& buf[0] != COMMENT_CHAR && buf[0] != END_COMMENT_CHAR)
			return (asm_parse_file_error(data, NULL, NULL));
	data->error_type = FILE_NO_OPEN;
	if (ret == -1)
		return (asm_parse_file_error(data, NULL, NULL));
	return (ret);
}

int		asm_error_header(t_asm *d, int nb_char, int empty, int r)
{
	if (nb_char == empty || r == -1)
		d->error_type = FILE_NO_OPEN;
	else if (d->name == 0 || d->comment == 0)
		d->error_type = d->name == 0 ? CHAMPION_NAME_ERROR : COMMENT_ERROR;
	return (asm_parse_file_error(d, NULL, NULL));
}

int		asm_extend1_header(t_asm *d, char **str, char *buf, int *i)
{
	int	r;

	r = 0;
	if (ft_strncmp(*str, NAME_CMD_STRING, d->lname) == 0)
	{
		*i = 0;
		ft_strdel(str);
		if ((r = asm_check_comment_name(d, buf, 1)) == -1)
			return (-1);
		return (r == 0 ? 0 : 1);
	}
	else if (ft_strncmp(*str, COMMENT_CMD_STRING, d->lcom) == 0)
	{
		*i = 0;
		ft_strdel(str);
		if ((r = asm_check_comment_name(d, buf, 2)) == -1)
			return (-1);
		return (r == 0 ? 0 : 1);
	}
	return (2);
}

int		asm_extend2_header(t_asm *d, char **str, int *i)
{
	if ((*str)[*i - 1] == '\n' || (*str)[*i - 1] == COMMENT_CHAR \
	|| (*str)[*i - 1] == END_COMMENT_CHAR)
	{
		if ((*str)[*i - 1] == COMMENT_CHAR
		|| (*str)[*i - 1] == END_COMMENT_CHAR)
			if (asm_search_end_comment(d) == -1)
				return (asm_parse_file_error(d, str, NULL));
		ft_strdel(str);
		*i = 0;
		return (1);
	}
	else if ((ft_strncmp((*str), NAME_CMD_STRING, *i) == 0 && d->name == 0)
	|| (ft_strncmp((*str), COMMENT_CMD_STRING, *i) == 0 && d->comment == 0))
		return (0);
	else if ((*str)[*i - 1] == ' ' || (*str)[*i - 1] == '\t')
	{
		*i = 0;
		ft_strdel(str);
		return (1);
	}
	else
		return (asm_parse_file_error(d, str, NULL));
	return (2);
}
