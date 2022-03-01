/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:11 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:46:12 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	rb(t_number *number)
{
	t_item	*temp;
	t_item	*last;

	if (!number->b)
		return ;
	temp = number->b;
	number->b = number->b->next;
	temp->next = 0;
	if (number->b)
	{
		last = number->b;
		while (last && last->next)
			last = last->next;
		last->next = temp;
	}
	else
		number->b = temp;
}
