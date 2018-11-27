/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:34:13 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 12:33:49 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*first_elem;

	if (lst && f)
	{
		new_list = f(lst);
		first_elem = new_list;
		while (lst->next)
		{
			lst = lst->next;
			new_list->next = f(lst);
			if (new_list->next == NULL)
				return (NULL);
			new_list = new_list->next;
		}
		return (first_elem);
	}
	return (NULL);
}
