/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:05:32 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 21:05:34 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **alst, void *new)
{
	t_list *elem;

	if (!*alst)
	{
		*alst = ft_lstnew(new);
		return ;
	}
	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = ft_lstnew(new);
}
