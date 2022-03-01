/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:45:32 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:45:35 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	pa(t_number *number)
{
	t_item	*temp;

	if (!number->b)
		return ;
	temp = number->b->next;
	number->b->next = number->a;
	number->a = number->b;
	number->b = temp;
}
