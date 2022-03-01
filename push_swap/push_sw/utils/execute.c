/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:57 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:58 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/lib.h"

void	execute(t_number *number, char *operation)
{
	dispatch(number, operation);
	ft_putstr_fd(operation, 1);
	ft_putchar_fd('\n', 1);
}
