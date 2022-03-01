/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:47 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:46:48 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	sb(t_number *number)
{
	t_item	*temp;

	if (!number->b || !number->b->next)
		return ;
	temp = number->b->next;
	number->b->next = number->b->next->next;
	temp->next = number->b;
	number->b = temp;
}
