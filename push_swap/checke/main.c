/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:40:56 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:02 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_operation	*op;
	t_stack		*stack;
	char		**operation;
	int			flag;

	if (ac == 1 || (ac == 2 && av[1][0] == '-'
			&& (av[1][1] == 'v' || av[1][1] == 'c')))
		return (0);
	op = NULL;
	stack = NULL;
	flag = 0;
	if (parsing_arg(av + 1, &flag) ||
			get_operation(&operation, 0, 0) ||
			((find_and_stock_op(operation, &op, av)) == NULL) ||
			(((stack = char_to_int(ac, av, &stack)) == NULL)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	call_op(op, stack, flag);
	free_all(operation, stack, op);
	return (0);
}
