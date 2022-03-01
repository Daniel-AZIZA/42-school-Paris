/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:34:51 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:34:56 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_activate_width_hexa(t_field *field, char *str)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = malloc(sizeof(char) * (field->width + 1))))
		return (NULL);
	if (field->flags.zero == 1)
	{
		s2[i++] = '0';
		s2[i++] = 'x';
		while (i < (field->width - ft_strlen(str)))
			s2[i++] = '0';
	}
	else
	{
		while (i < (field->width - ft_strlen(str) - 2))
			s2[i++] = ' ';
		s2[i++] = '0';
		s2[i++] = 'x';
	}
	ft_strncpy(s2 + i, str, field->width - i + 1);
	return (s2);
}

char	*ft_activate_minus_hexa(t_field *field, char *str)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	j = 2;
	k = 0;
	i = ft_strlen(str);
	if (i < field->width)
		i = field->width;
	if (!(s2 = malloc(sizeof(char) * (i + 2) + 1)))
		return (NULL);
	s2[0] = '0';
	s2[1] = 'x';
	while (k < ft_strlen(str))
		s2[j++] = str[k++];
	while (j < field->width)
		s2[j++] = ' ';
	s2[j] = '\0';
	return (s2);
}
