/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:47:00 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:47:00 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/lib.h"
#include <stdio.h>

void	sort_three(t_number *number)
{
	size_t	index;

	if (!number->a || !number->a->next || check(number->a))
		return ;
	index = getindex(number->a, getmax(number->a));
	if (index == 0)
		execute(number, "ra");
	else if (index == 1)
		execute(number, "rra");
	if (number->a->data > number->a->next->data)
		execute(number, "sa");
}

void	sort_small(t_number *number)
{
	size_t	index;
	size_t	len;

	while ((len = getlen(number->a)) > 3)
	{
		index = getindex(number->a, getmin(number->a));
		if (index < len / 2)
			while (index--)
				execute(number, "ra");
		else
			while (index++ < len)
				execute(number, "rra");
		execute(number, "pb");
	}
	sort_three(number);
	while (number->b)
		execute(number, "pa");
}
