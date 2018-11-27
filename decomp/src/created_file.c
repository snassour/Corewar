/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 23:52:11 by cbrian            #+#    #+#             */
/*   Updated: 2018/09/24 17:01:25 by cbrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deasm.h"

void		created_file(char *argv, char **cor)
{
	char *tmp;

	tmp = ft_strndup(argv, ft_strlen(argv) - 4);
	*cor = ft_strjoin(tmp, "_deasm.s");
	free(tmp);
}
