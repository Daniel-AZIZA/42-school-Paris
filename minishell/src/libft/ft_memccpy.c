/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:17:28 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:17:30 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	int					flag;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	c = (unsigned char)c;
	flag = 0;
	if (ft_memchr(s, c, n))
	{
		n = (unsigned char *)ft_memchr(s, c, n) - s + 1;
		flag = 1;
	}
	while (n--)
		*d++ = *s++;
	return ((flag) ? d : 0);
}
