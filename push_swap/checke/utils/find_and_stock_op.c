/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_stock_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:08 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:12 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static	t_operation	*ft_create_elem(void (*f)(t_stack **first),
		void (*push)(t_stack **stack_a, t_stack **stack_b),
		char *s, int *count)
{
	t_operation	*new_elem;

	new_elem = NULL;
	if (!(new_elem = malloc(sizeof(*new_elem))))
		return (NULL);
	if (s[0] == 'p' || s[1] == 's' ||
			(s[0] == 'r' && s[1] == 'r' && s[2] == '\0')
			|| s[2] == 'r')
		new_elem->push = push;
	else
		new_elem->f = f;
	new_elem->str = s;
	new_elem->next = NULL;
	(*count)++;
	return (new_elem);
}

static	void		ft_lstadd_back(t_operation **alst, t_operation *new)
{
	t_operation	*begin;

	begin = NULL;
	if (!*alst)
		*alst = new;
	else
	{
		begin = *alst;
		while (begin && begin->next)
			begin = begin->next;
		begin->next = new;
	}
}

static	void		find_and_stock_op_annexe_2(char **operation,
		unsigned int i, t_operation **op, int *count)
{
	if (operation[i][0] == 'r' && operation[i][1] == 'r'
			&& operation[i][2] == 'r')
		ft_lstadd_back(op, ft_create_elem(NULL, &rrr, "rrr", count));
}

static	void		find_and_stock_op_annexe(char **operation,
		unsigned int i, t_operation **op, int *count)
{
	if (operation[i][0] == 's' && operation[i][1] == 'a')
		ft_lstadd_back(op, ft_create_elem(&swap_a, NULL, "sa", count));
	if (operation[i][0] == 's' && operation[i][1] == 'b')
		ft_lstadd_back(op, ft_create_elem(&swap_b, NULL, "sb", count));
	if (operation[i][0] == 's' && operation[i][1] == 's')
		ft_lstadd_back(op, ft_create_elem(NULL, &ss, "ss", count));
	if (operation[i][0] == 'p' && operation[i][1] == 'a')
		ft_lstadd_back(op, ft_create_elem(NULL, &pa, "pa", count));
	if (operation[i][0] == 'p' && operation[i][1] == 'b')
		ft_lstadd_back(op, ft_create_elem(NULL, &pb, "pb", count));
	if (operation[i][0] == 'r' && operation[i][1] == 'a')
		ft_lstadd_back(op, ft_create_elem(&ra_rb, NULL, "ra", count));
	if (operation[i][0] == 'r' && operation[i][1] == 'b')
		ft_lstadd_back(op, ft_create_elem(&rra_rrb, NULL, "rb", count));
	if (operation[i][0] == 'r' && operation[i][1] == 'r'
			&& operation[i][2] == '\0')
		ft_lstadd_back(op, ft_create_elem(NULL, &rr, "rr", count));
	if (operation[i][0] == 'r' && operation[i][1] == 'r'
			&& operation[i][2] == 'a')
		ft_lstadd_back(op, ft_create_elem(&rra_rrb, NULL, "rra", count));
	if (operation[i][0] == 'r' && operation[i][1] == 'r'
			&& operation[i][2] == 'b')
		ft_lstadd_back(op, ft_create_elem(&ra_rb, NULL, "rrb", count));
	find_and_stock_op_annexe_2(operation, i, op, count);
}

t_operation			*find_and_stock_op(char **operation,
		t_operation **op, char **av)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (av[0][0] == '-' && (av[0][1] == 'v' || av[0][1] == 'c'))
		i = 1;
	while (operation && operation[i])
	{
		find_and_stock_op_annexe(operation, i, op, &count);
		i++;
	}
	if (i != count)
		return (NULL);
	return (*op);
}
