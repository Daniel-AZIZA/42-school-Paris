/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:36:04 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:36:06 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_atoi(const char *str, int len)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	if (str[i] < '0' && str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && i < len)
	{
		if (str[i] < '0' && str[i] > '9')
			break ;
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

int		print_numbers(long num)
{
	int		div;
	int		count;
	char	c;

	div = 1;
	count = 0;
	while (num / div >= 10)
	{
		div = div * 10;
	}
	while (div != '\0')
	{
		c = '0' + num / div;
		write(1, &c, 1);
		count++;
		num = num % div;
		div = div / 10;
	}
	return (count);
}

int		ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		write(1, "-", 1);
		count = 1 + print_numbers(-n);
	}
	else
	{
		count = print_numbers(n);
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
