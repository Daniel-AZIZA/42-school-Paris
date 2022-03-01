/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:42:22 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:42:23 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void		ra_rb(t_stack **first)
{
	t_stack *stack;

	if ((*first) != NULL && (*first)->next != NULL)
	{
		stack = (*first);
		while (stack->next)
			stack = stack->next;
		stack->next = (*first);
		stack = (*first)->next;
		(*first)->next = 0;
		(*first) = stack;
	}
}

void		rra_rrb(t_stack **first)
{
	t_stack	*stack;

	if ((*first) != NULL && (*first)->next != NULL)
	{
		stack = (*first);
		while (stack->next->next)
			stack = stack->next;
		stack->next->next = (*first);
		(*first) = stack->next;
		stack->next = 0;
	}
}

void		rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a);
	rra_rrb(stack_b);
}

void		rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a);
	ra_rb(stack_b);
}
