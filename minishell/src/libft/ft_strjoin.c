/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:24:58 by daziza            #+#    #+#             */
/*   Updated: 2020/11/19 13:59:33 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char *)malloc(sizeof(str) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
		str[i++] = ((char *)s2)[j++];
	str[i] = '\0';
	return (str);
}
