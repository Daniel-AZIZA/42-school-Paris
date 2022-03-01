/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:57:24 by daziza            #+#    #+#             */
/*   Updated: 2020/11/19 14:02:31 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
