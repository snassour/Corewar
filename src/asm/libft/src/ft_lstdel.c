/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <snassour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:08:25 by snassour          #+#    #+#             */
/*   Updated: 2015/12/02 12:33:47 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*blst;

	if (alst)
	{
		while (*alst)
		{
			blst = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = blst;
		}
	}
	*alst = NULL;
}
