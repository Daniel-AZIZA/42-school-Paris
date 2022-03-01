/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:18 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:30 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	free_op(char **operation)
{
	unsigned int	i;

	i = 0;
	while (operation[i])
	{
		free(operation[i]);
		i++;
	}
	free(operation);
}

static void	t_free_op(t_operation *op)
{
	t_operation *old_elem;

	if (op == NULL)
		return ;
	while (op != NULL)
	{
		old_elem = op;
		op = op->next;
		free(old_elem);
	}
	op = NULL;
}

static void	free_stack(t_stack *stack)
{
	t_stack *old_elem;

	if (stack == NULL)
		return ;
	while (stack != NULL)
	{
		old_elem = stack;
		stack = stack->next;
		free(old_elem);
	}
	stack = NULL;
}

void		free_all(char **operation, t_stack *stack, t_operation *op)
{
	if (op)
		t_free_op(op);
	if (operation)
		free_op(operation);
	if (stack)
		free_stack(stack);
}
