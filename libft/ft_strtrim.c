/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:02:38 by daziza            #+#    #+#             */
/*   Updated: 2020/12/02 18:02:45 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen((char *)s1);
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	newstring = ft_substr((char*)s1, 0, size_s + 1);
	return (newstring);
}
