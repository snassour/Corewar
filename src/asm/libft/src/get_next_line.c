/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 19:09:11 by snassour          #+#    #+#             */
/*   Updated: 2016/10/15 18:28:00 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strjoinfree(char **str, char **buf, int mode)
{
	char	*new;

	new = NULL;
	if (!*str && !*buf)
		return (NULL);
	if (*str && *buf)
		new = ft_strjoin(*str, *buf);
	else if (*str)
		new = ft_strdup(*str);
	else if (*buf)
		new = ft_strdup(*buf);
	if (*str && (mode == 1 || mode == 3))
		ft_strdel(str);
	if (*buf && (mode == 2 || mode == 3))
		ft_strdel(buf);
	return (new);
}

static int	ft_gnlcpy(int n_read, char **buf, char **str, char **line)
{
	char	*chr;
	char	*new;

	ft_strdel(buf);
	ft_strdel(line);
	if (!*str)
		return (-1);
	chr = ft_strchr(*str, '\n');
	if (n_read == 0 && chr == NULL)
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (!ft_strequ(*line, ""));
	}
	chr = ft_strchr(*str, '\n');
	*line = ft_strsub(*str, 0, chr - *str);
	new = ft_strdup(++chr);
	ft_strdel(str);
	*str = new;
	return (1);
}

static int	ft_gnl_error(char **buf, int fd, char **line, int mode)
{
	if (mode == 0)
	{
		if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
			return (-1);
		if (!(*buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		if (read(fd, *buf, 0) < 0)
		{
			ft_strdel(buf);
			return (-1);
		}
		return (0);
	}
	ft_strdel(line);
	ft_strdel(buf);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[1024];
	int			n_read;
	char		*chr;
	char		*buf;

	buf = NULL;
	if (ft_gnl_error(&buf, fd, line, 0) == -1)
	{
		if (fd >= 0 && read(fd, NULL, 0) < 0 && str[fd])
			ft_strdel(&str[fd]);
		return (-1);
	}
	n_read = 0;
	str[fd] = (str[fd] ? str[fd] : ft_strdup(""));
	chr = (str[fd] ? ft_strchr(str[fd], '\n') : NULL);
	while (chr == NULL && (n_read = read(fd, buf, BUFF_SIZE)))
	{
		if (n_read < 0)
			return (ft_gnl_error(&buf, fd, &str[fd], n_read));
		buf[n_read] = 0;
		str[fd] = ft_strjoinfree(&str[fd], &buf, 1);
		chr = ft_strchr(buf, '\n');
	}
	return (ft_gnlcpy(n_read, &buf, &str[fd], line));
}
