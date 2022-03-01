/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:35:33 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:35:36 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	ft_count_c(long n)
{
	long count;
	long div;

	count = 1;
	div = 1;
	while (n / div >= 10)
	{
		div *= 10;
		count++;
	}
	return (count);
}

static char	*ft_save(char *str, long n)
{
	long	div;
	int		i;

	div = 1;
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n / div >= 10)
		div *= 10;
	while (div != 0)
	{
		str[i] = n / div + '0';
		n = n % div;
		div = div / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_count_c(-nb) + 2))))
			return (NULL);
		str = ft_save(str, nb);
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_count_c(nb) + 1))))
			return (NULL);
		str = ft_save(str, nb);
	}
	return (str);
}

char		*ft_itoa_u(unsigned int n)
{
	char			*str;
	unsigned long	nb;

	nb = (unsigned long)n;
	if (!(str = (char*)malloc(sizeof(char) * (ft_count_c(nb) + 1))))
		return (NULL);
	ft_save(str, nb);
	return (str);
}
