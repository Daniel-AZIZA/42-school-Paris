/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:42:37 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:42:39 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_stack		*ft_create_elem_2(int nbr)
{
	t_stack *new_elem;

	new_elem = NULL;
	if (!(new_elem = malloc(sizeof(*new_elem))))
		return (NULL);
	new_elem->nb = nbr;
	new_elem->next = NULL;
	return (new_elem);
}

static void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*begin;

	if (!*alst)
		*alst = new;
	else
	{
		begin = *alst;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}

t_stack		*char_to_int(int ac, char **av, t_stack **stack)
{
	int		i;
	t_stack	*new;

	i = 0;
	if (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'c'))
		i = 1;
	while (i < (ac - 1))
	{
		if (!(new = ft_create_elem_2(ft_atoi(av[i + 1]))))
			return (NULL);
		ft_lstadd_back(stack, new);
		i++;
	}
	return (*stack);
}

void		free_stack_b(t_stack **b)
{
	t_stack *old_elem;

	if (!*b)
		return ;
	while ((*b)->next)
	{
		old_elem = *b;
		*b = old_elem->next;
		free(old_elem);
	}
	*b = NULL;
}

void		call_op(t_operation *op, t_stack *stack, int flag)
{
	t_stack		*stack_b;

	stack_b = NULL;
	if (flag == 1)
		print_stack(stack, stack_b, op);
	while (op)
	{
		if (op->str[0] == 'p' || op->str[1] == 's'
			|| (op->str[0] == 'r' && op->str[1] == 'r'
				&& op->str[2] == '\0') || op->str[2] == 'r')
			op->push(&stack, &stack_b);
		else
		{
			if (op->str[1] == 'b' || op->str[2] == 'b')
				op->f(&stack_b);
			else
				op->f(&stack);
		}
		if (flag == 1)
			print_stack(stack, stack_b, op);
		if (op->next == NULL && flag == 2)
			print_stack_color(stack, stack_b, op);
		op = op->next;
	}
	is_order(stack, stack_b);
}
