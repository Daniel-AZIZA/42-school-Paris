/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:43:58 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:00 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef	struct s_item	t_item;
struct					s_item
{
	int		data;
	t_item	*next;
};

typedef struct			s_number
{
	t_item	*a;
	t_item	*b;
}						t_number;
#endif
