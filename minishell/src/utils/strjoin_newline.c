/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_newline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:33:40 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:33:43 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char
	*strjoin_newline(char *s1, char *s2)
{
	char	*new;
	size_t	len_1;
	size_t	len_2;
	size_t	len;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	len = len_1 + len_2 + 1;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len_1);
	new[len_1] = '\n';
	ft_memcpy(new + len_1 + 1, s2, len_2);
	new[len] = 0;
	return (new);
}
