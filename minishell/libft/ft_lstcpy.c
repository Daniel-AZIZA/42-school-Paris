/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:16:09 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:16:10 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstcpy(t_list *lst, void (*del)(void *))
{
	t_list *dst;
	t_list *dst_next;

	if (!(dst = ft_lstnew(lst->content)))
		return (NULL);
	dst_next = dst;
	while (lst->next)
	{
		if (!(dst_next->next = ft_lstnew(lst->next->content)))
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		lst = lst->next;
		dst_next = dst_next->next;
	}
	return (dst);
}
