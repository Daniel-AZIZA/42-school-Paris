/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 23:46:52 by daziza            #+#    #+#             */
/*   Updated: 2020/12/02 17:43:31 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s)
		if (*s++ != c)
		{
			l++;
			while (*s && *s != c)
				s++;
		}
	return (l);
}

static size_t	ft_charlen(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

char		**ft_split(char const *s, char c)
{
	char			**split;
	const char		**init;
	const char		*start;

	if (!s || !(split = (char**)malloc(sizeof(char*) * ft_wordlen(s, c) + 1)))
		return (NULL);
	split[ft_wordlen(s, c)] = 0;
	init = (const char**)split;
	while (1)
	{
		if (*s && *s != c)
		{
			if (!(*split = malloc(sizeof(char) * ft_charlen(s, c) + 1)))
				return (NULL);
			start = *split;
			while (*s && *s != c)
				*(*split)++ = *s++;
			**split = '\0';
			*split = (char *)start;
			split++;
		}
		if (!*s++)
			break ;
	}
	return ((char**)init);
}
