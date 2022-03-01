/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:35:05 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:35:21 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = (char*)b;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char*)s;
	if (c == '\0')
		return (t + ft_strlen(t));
	else
		while (t[i])
		{
			if (t[i] == c)
				return (t + i);
			i++;
		}
	return (NULL);
}

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strnlen(const char *s, int n)
{
	int	i;

	i = 0;
	while (i < n && s[i])
		i++;
	return (i);
}
