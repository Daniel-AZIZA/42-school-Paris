/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:43:05 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:43:06 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	print_stack_color(t_stack *a, t_stack *b, t_operation *op)
{
	static int	first = 1;

	if (first == 0)
		printf("exec %s:\n", op->str);
	if (first == 1)
		printf("\nlast operation : \033[0;31m\n\n");
	print_stack_2(a, b);
	printf("\033[0;37m_  _\n");
	printf("\033[0;37ma  b\n\n");
	first = 0;
}

int		get_flag(char **av, int *flag)
{
	if (av[0][0] == '-' && (av[0][1] == 'v' || av[0][1] == 'c'))
	{
		if (av[0][1] == 'v')
			*flag = 1;
		if (av[0][1] == 'c')
			*flag = 2;
		return (1);
	}
	return (0);
}
