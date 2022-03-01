/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:45:56 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:45:57 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	ra(t_number *number)
{
	t_item	*temp;
	t_item	*last;

	if (!number->a)
		return ;
	temp = number->a;
	number->a = number->a->next;
	temp->next = 0;
	if (number->a)
	{
		last = number->a;
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	else
		number->a = temp;
}
