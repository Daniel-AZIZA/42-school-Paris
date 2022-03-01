/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:41 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:43 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../includes/list.h"

bool	check(t_item *item)
{
	while (item && item->next)
	{
		if (item->data > item->next->data)
			return (false);
		item = item->next;
	}
	return (true);
}
