/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:34:42 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:34:43 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_activate_width(t_field *field, char *str, int len)
{
	char	*s2;
	long	i;
	long	j;

	i = 0;
	j = 0;
	if (!(s2 = malloc(sizeof(char) * (field->width + 1))))
		return (NULL);
	while (i < (field->width - len))
	{
		if (field->flags.zero == 1)
			s2[i++] = '0';
		else
			s2[i++] = ' ';
	}
	while (i < field->width)
		s2[i++] = str[j++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_activate_width_int_zero(t_field *field)
{
	char	*s2;
	long	i;

	i = 0;
	if (!(s2 = malloc(sizeof(char) * (field->width + 1))))
		return (NULL);
	while (i < field->width)
		s2[i++] = ' ';
	s2[i] = '\0';
	return (s2);
}

char	*ft_activate_width_int(char *s1, t_field *field, int len)
{
	char	*s2;
	long	i;
	long	j;

	i = 0;
	j = 0;
	if (!(s2 = malloc(sizeof(char) * (field->width + 1))))
		return (NULL);
	if (s1[0] == '-' && field->flags.zero == 1)
	{
		s2[i++] = '-';
		j++;
		len--;
	}
	while (i < (field->width - len))
	{
		if (field->flags.zero == 1)
			s2[i++] = '0';
		else
			s2[i++] = ' ';
	}
	while (i < field->width)
		s2[i++] = s1[j++];
	s2[i] = '\0';
	return (s2);
}

char	*ft_activate_minus(t_field *field, char *str, int len)
{
	char	*s2;
	int		j;

	j = 0;
	if (!(s2 = malloc(sizeof(char) * (field->width) + 1)))
		return (NULL);
	while (j < len)
	{
		s2[j] = str[j];
		j++;
	}
	while (j < field->width)
		s2[j++] = ' ';
	s2[j] = '\0';
	return (s2);
}
