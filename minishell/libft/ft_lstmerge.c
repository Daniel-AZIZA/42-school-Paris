/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:16:42 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:16:43 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *elem;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	elem = *begin_list1;
	while (elem->next)
		elem = elem->next;
	elem->next = begin_list2;
}
