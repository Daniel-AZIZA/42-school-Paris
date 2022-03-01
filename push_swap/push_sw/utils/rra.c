/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:21 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:46:22 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	rra(t_number *number)
{
	t_item	*last;
	t_item	*temp;

	if (!number->a || !number->a->next)
		return ;
	last = number->a;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->a;
	number->a = temp;
}
