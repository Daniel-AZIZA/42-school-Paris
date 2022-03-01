/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:45:50 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:45:51 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	pb(t_number *number)
{
	t_item	*temp;

	if (!number->a)
		return ;
	temp = number->a->next;
	number->a->next = number->b;
	number->b = number->a;
	number->a = temp;
}
