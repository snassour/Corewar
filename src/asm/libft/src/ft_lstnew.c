/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:03:14 by snassour          #+#    #+#             */
/*   Updated: 2015/12/01 20:48:12 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = NULL;
	lst = (t_list *)malloc(sizeof(t_list));
	if (lst != NULL)
	{
		if (content == NULL)
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		else
		{
			if (!(lst->content = (void *)malloc(content_size)))
				return (NULL);
			ft_memcpy(lst->content, content, content_size);
			lst->content_size = content_size;
		}
		lst->next = NULL;
	}
	return (lst);
}
