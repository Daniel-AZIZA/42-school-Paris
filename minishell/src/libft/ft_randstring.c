/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:18:28 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:18:30 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include "libft.h"

char	*ft_randstring(int size)
{
	char	*str;
	char	c;
	int		i;

	srand(time(NULL));
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		c = rand();
		str[i] = (c == 0 ? 1 : c);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_prandstring(int size)
{
	char	*str;
	char	c;
	int		i;

	srand(time(NULL));
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		c = rand();
		while (!ft_isprint(c))
			c = rand();
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_randmem(int size)
{
	char	*str;
	char	c;
	int		i;

	srand(time(NULL));
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		c = rand();
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
