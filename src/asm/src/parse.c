/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:53:45 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:53:48 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		asm_instruction(char *line, t_asm *data)
{
	int		i;
	int		j;
	char	*label;

	if (ft_strcmp(line, "") == 0)
		return (0);
	data->error_type = data->name == 0 ? CHAMPION_NAME_ERROR : COMMENT_ERROR;
	if (data->name == 0 || data->comment == 0)
		return (asm_parse_file_error(data, &line, NULL));
	label = NULL;
	j = 0;
	while (line[j] && ft_strchr(LABEL_CHARS, line[j]))
		++j;
	if (line[j] == LABEL_CHAR)
		label = line + j;
	i = 0;
	if (label)
		i = asm_checklabel(line, label, data);
	if (i < 0)
		return (-1);
	j = (i == 1 ? label + 1 - line : 0);
	while (line[j] && (line[j] == '\t' || line[j] == ' '))
		++j;
	i = (line[j] == '\0' ? i : asm_checkcmd(line, j, data));
	return (i);
}

int		asm_check_new_line(char *nc, t_asm *data)
{
	int		i;

	i = 0;
	data->line_error++;
	if ((i = asm_instruction(nc, data)) >= 0)
		return (1);
	return (i < 0 ? -1 : 1);
}

int		asm_last_line_check(t_asm *data, int gnl_ret)
{
	char	buf[2];

	if (gnl_ret == 0)
	{
		lseek(data->fd, -1, SEEK_END);
		read(data->fd, buf, 1);
		if (buf[0] != '\n')
			data->new_line = 0;
		else
			data->new_line = 1;
	}
	close(data->fd);
	ft_strdel(&(data->str));
	get_next_line(data->fd, &(data->str));
	if (gnl_ret == -1 || data->new_line == 0)
	{
		data->error_type = (gnl_ret == -1 ? FILE_NO_OPEN : NO_NEW_LINE);
		return (asm_parse_file_error(data, NULL, NULL));
	}
	return (1);
}

int		asm_read_instructions(t_asm *data, int *gnl_ret)
{
	char	*nc;

	while ((*gnl_ret = get_next_line(data->fd, &(data->str))) > 0 && data->str)
	{
		data->error_type = MFAIL;
		nc = NULL;
		if (!(nc = asm_removecomment(data->str)))
			return (asm_parse_file_error(data, NULL, &nc));
		if (ft_strcmp("", data->str) == 0)
			data->new_line = 1;
		else
			data->new_line = 0;
		if (asm_check_new_line(nc, data) != 1)
			return (-1);
		ft_strdel(&(data->str));
		ft_strdel(&nc);
		asm_reinit_data(&data);
	}
	return (0);
}

int		asm_parse_file(t_asm *data)
{
	int		i;

	ft_strdel(&(data->str));
	if (asm_header_2(data) == -1)
		return (asm_close_error(data));
	data->line_error++;
	data->new_line = 0;
	i = 0;
	if (asm_read_instructions(data, &i) == -1)
		return (-1);
	if (asm_last_line_check(data, i) == -1)
		return (-1);
	data->error_type = LABEL_NOTSET;
	data->header->prog_size = asm_bigendian(data->pc, 4);
	if (data->header->prog_size == 0)
	{
		asm_error(FILE_NO_INSTR, NULL, data);
		return (-1);
	}
	data->header->magic = asm_bigendian(COREWAR_EXEC_MAGIC, 4);
	if (asm_replace_labels(data) == -1)
		return (-1);
	asm_exit_success(data);
	return (1);
}
