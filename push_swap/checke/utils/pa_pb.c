/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:54 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:56 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_list_push_front(t_stack **begin_list, int data)
{
	t_stack *list;

	if (*begin_list)
	{
		list = ft_create_elem_2(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem_2(data);
}

int		remove_last_elem(t_stack **stack)
{
	t_stack		*head;
	int			tmp;

	tmp = 0;
	head = *stack;
	if (!head->next)
	{
		tmp = head->nb;
		free(head);
		*stack = NULL;
		return (tmp);
	}
	while (head->next->next)
		head = head->next;
	tmp = head->next->nb;
	free(head->next);
	head->next = NULL;
	return (tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int			nbr;

	if (*stack_b)
	{
		nbr = remove_last_elem(stack_b);
		ft_list_push_front(stack_a, nbr);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_a)
	{
		tmp = *stack_b;
		if (!tmp)
			*stack_b = ft_create_elem_2((*stack_a)->nb);
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_create_elem_2((*stack_a)->nb);
		}
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}
