/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:42 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:44 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	is_order(t_stack *stack_a, t_stack *stack_b)
{
	int ordered;
	int prev_ordered;

	ordered = 1;
	if (stack_b == NULL)
	{
		while (stack_a && stack_a->next)
		{
			prev_ordered = ordered;
			if (stack_a->nb > stack_a->next->nb)
				ordered = 0;
			if (prev_ordered && ordered)
				ordered = 1;
			else
				ordered = 0;
			stack_a = stack_a->next;
		}
	}
	if (!ordered || stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
