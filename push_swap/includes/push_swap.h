/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:44:12 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:13 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "list.h"

t_item	*parse(char **args);
void	freeitem(t_item *item);
void	dispatch(t_number *number, char *operation);
void	execute(t_number *number, char *operation);
void	sort_small(t_number *number);
void	sort(t_number *number);
bool	check(t_item *item);
#endif
