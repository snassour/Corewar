/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 05:52:03 by snassour          #+#    #+#             */
/*   Updated: 2018/10/01 05:52:08 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	asm_exit_success(t_asm *data)
{
	int	i;

	i = ft_strlen(data->dot_s_name);
	if (asm_generate_corfile(data, i) == -1)
		return ;
	asm_write_color("\033[1;32m", ft_strlen("\033[1;32m"), 1);
	ft_putstr("Generating Corewar file : ");
	write(1, data->dot_s_name, i - 1);
	write(1, "cor\n", 4);
	asm_write_color("\033[0m", ft_strlen("\033[0m"), 1);
	i = (i + 3);
}

int		asm_verify_entry(int ac, char **av, int i)
{
	int len;

	if (ac < 2)
	{
		asm_error(NO_FILE, NULL, NULL);
		return (-1);
	}
	len = ft_strlen(av[i]);
	if (av[i][len - 2] == '.' && av[i][len - 1] == 's' && len == 2)
	{
		asm_error(WRONG_EXTENSION, av[i], NULL);
		return (-1);
	}
	if (av[i][len - 2] != '.' || av[i][len - 1] != 's')
	{
		asm_error(WRONG_EXTENSION, av[i], NULL);
		return (-1);
	}
	return (0);
}

int		asm_verify_format(t_asm *data)
{
	if ((data->fd = open(data->dot_s_name, O_RDONLY)) == -1)
	{
		asm_error(FILE_NO_OPEN, NULL, data);
		return (-1);
	}
	data->line_error = 0;
	asm_parse_file(data);
	if (data->begin)
		asm_destroy_corlist(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_asm	*data;
	int		i;

	i = 0;
	if (ac == 1)
		asm_error(NO_FILE, NULL, NULL);
	while (++i < ac)
	{
		data = NULL;
		if (asm_verify_entry(ac, av, i))
			continue ;
		data = asm_init_data();
		if (!data)
		{
			asm_error(MFAIL, NULL, NULL);
			continue ;
		}
		data->dot_s_name = av[i];
		asm_verify_format(data);
		asm_destroy_data(&data);
	}
	return (0);
}
