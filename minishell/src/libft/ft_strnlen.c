/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:20:09 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:20:11 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && str[i])
		i++;
	return (i);
}
