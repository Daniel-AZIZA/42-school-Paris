/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:33:48 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:33:55 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*ft_strndup_width(char *s1, int n)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!(s2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < (n - j))
		s2[i++] = ' ';
	while (i < n)
		s2[i++] = s1[k++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup_width_x(char *s1, int n)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!(s2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < (n - j))
		s2[i++] = '0';
	while (i < n)
		s2[i++] = s1[k++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup_width_d(char *s1, int n)
{
	char	*s2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	if (!(s2 = malloc(sizeof(char) * (n + 2))))
		return (NULL);
	if (s1[0] == '-')
	{
		s2[i++] = '-';
		s1++;
		n++;
	}
	while (i < (n - ft_strlen(s1)))
		s2[i++] = '0';
	while (i < n)
		s2[i++] = s1[k++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup(char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	while (i < n)
		s2[i++] = '0';
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup_simple(char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
