/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:08:51 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 16:12:40 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list *begin, void *content, size_t content_size)
{
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		begin->next = ft_lstnew(content, content_size);
	}
}
