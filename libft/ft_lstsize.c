/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:51:24 by daziza            #+#    #+#             */
/*   Updated: 2020/11/21 17:41:38 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*copy_lst;
	int		i;

	i = 0;
	copy_lst = lst;
	while (copy_lst)
	{
		copy_lst = copy_lst->next;
		i++;
	}
	return (i);
}
