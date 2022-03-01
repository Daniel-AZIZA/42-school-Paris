/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:19:50 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:19:53 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	while (i < n && res == 0)
	{
		if (s1[i] == 0 && s2[i] == 0)
			return (0);
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (res);
}
