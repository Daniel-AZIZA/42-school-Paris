/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:18:36 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:18:37 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strbegin(const char *str, const char *begin)
{
	size_t	i;

	i = 0;
	while (begin[i] && str[i] && begin[i] == str[i])
		i++;
	if (!begin[i])
		return (1);
	return (0);
}
