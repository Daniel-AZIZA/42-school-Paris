/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:20:03 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:20:05 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strndup(const char *str, size_t n)
{
	char *out;

	out = malloc(sizeof(char) * n + 1);
	ft_strncpy(out, str, n);
	out[n] = 0;
	return (out);
}
