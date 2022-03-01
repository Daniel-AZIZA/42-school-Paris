/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:46:39 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:46:40 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/list.h"

void	sa(t_number *number)
{
	t_item	*temp;

	if (!number->a || !number->a->next)
		return ;
	temp = number->a->next;
	number->a->next = number->a->next->next;
	temp->next = number->a;
	number->a = temp;
}
