/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:10:54 by daziza            #+#    #+#             */
/*   Updated: 2020/11/21 17:40:55 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
