/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:17:42 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:17:44 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memreplace(void *source, char a, char b, size_t size)
{
	char	*str;
	size_t	i;

	str = source;
	i = -1;
	while (++i < size)
		if (str[i] == a)
			str[i] = b;
	return (source);
}
