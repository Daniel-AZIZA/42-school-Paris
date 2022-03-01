/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:42:50 by daziza            #+#    #+#             */
/*   Updated: 2020/05/05 12:12:59 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	if (!dest)
		return (0);
	count = 0;
	while (src[count])
		++count;
	if (size == 0)
		return (count);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
