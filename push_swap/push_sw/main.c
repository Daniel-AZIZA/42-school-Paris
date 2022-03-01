/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:32 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:35 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/lib.h"

int		main(int argc, char **argv)
{
	t_number	number;

	(void)argc;
	argv++;
	if (!*argv)
		return (0);
	number = (t_number){parse(argv), 0};
	if (!number.a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!check(number.a))
		sort(&number);
	freeitem(number.a);
	freeitem(number.b);
	return (0);
}
