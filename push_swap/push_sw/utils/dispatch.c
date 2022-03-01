/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:49 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:51 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/operations.h"

void	dispatch(t_number *number, char *operation)
{
	if (ft_equals(operation, "sa"))
		sa(number);
	else if (ft_equals(operation, "sb"))
		sb(number);
	else if (ft_equals(operation, "ss"))
		ss(number);
	else if (ft_equals(operation, "pa"))
		pa(number);
	else if (ft_equals(operation, "pb"))
		pb(number);
	else if (ft_equals(operation, "ra"))
		ra(number);
	else if (ft_equals(operation, "rb"))
		rb(number);
	else if (ft_equals(operation, "rr"))
		rr(number);
	else if (ft_equals(operation, "rra"))
		rra(number);
	else if (ft_equals(operation, "rrb"))
		rrb(number);
	else if (ft_equals(operation, "rrr"))
		rrr(number);
	else
		ft_putstr_fd("Error\n", 2);
}
