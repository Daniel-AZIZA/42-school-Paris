/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:27 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:46:28 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	rrb(t_number *number)
{
	t_item	*last;
	t_item	*temp;

	if (!number->b || !number->b->next)
		return ;
	last = number->b;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->b;
	number->b = temp;
}
