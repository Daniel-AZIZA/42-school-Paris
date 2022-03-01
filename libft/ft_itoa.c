/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:32:39 by daziza            #+#    #+#             */
/*   Updated: 2020/11/19 13:05:26 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	unsigned int	len[2];
	int				tmp;
	char			*s;

	tmp = n;
	len[0] = 1;
	len[1] = 1;
	if (n < 0)
		++len[0];
	while ((tmp /= 10))
	{
		len[1] *= 10;
		len[0]++;
	}
	if (!(s = (char *)malloc(sizeof(char) * len[0] + 1)))
		return (NULL);
	if (n < 0 && (*s++ = '-'))
		n *= -1;
	while (len[1])
	{
		*s++ = ('0' + (n / len[1]) % 10);
		len[1] /= 10;
	}
	*s = '\0';
	return (s - len[0]);
}
