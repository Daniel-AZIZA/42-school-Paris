/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:20:14 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:20:16 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int index_find;

	i = 0;
	if (needle[0] == '\0' ||
			(needle == haystack && ft_strlen(needle) <= len))
		return ((char *)haystack);
	while (haystack[i])
	{
		index_find = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + index_find] == needle[index_find] &&
				i + index_find < (int)len)
			{
				index_find++;
				if (needle[index_find] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
