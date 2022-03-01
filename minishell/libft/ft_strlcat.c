/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:44:41 by daziza            #+#    #+#             */
/*   Updated: 2020/05/03 20:51:06 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;

	dstlen = ft_strnlen(dst, size);
	if (size > dstlen)
		return (dstlen + ft_strlcpy(dst + dstlen, src, size - dstlen));
	return (dstlen + ft_strlen(src));
}
