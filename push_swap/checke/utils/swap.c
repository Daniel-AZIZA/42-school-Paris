/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:42:30 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:42:31 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	swap_a(t_stack **first)
{
	t_stack *stack;
	t_stack *tmp;

	stack = (*first);
	if (stack != NULL && stack->next != NULL)
	{
		(*first) = stack->next;
		tmp = stack->next->next;
		stack->next->next = stack;
		stack->next = tmp;
	}
}

void	swap_b(t_stack **first)
{
	t_stack	*stack;
	int		tmp;

	stack = (*first);
	if (stack != NULL && stack->next != NULL)
	{
		while (stack && stack->next->next)
			stack = stack->next;
		tmp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = tmp;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
