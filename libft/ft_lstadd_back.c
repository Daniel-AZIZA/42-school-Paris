/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:04:54 by daziza            #+#    #+#             */
/*   Updated: 2020/11/21 17:39:22 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (!*alst)
		*alst = new;
	else
	{
		begin = *alst;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}
