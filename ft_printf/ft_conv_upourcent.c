/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_upourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:34:30 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:34:31 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_pourcent(va_list argptr, t_field *field)
{
	char	s1[2];
	char	*s2;
	int		n;

	(void)argptr;
	s1[0] = '%';
	s1[1] = '\0';
	if (field->flags.minus == 1 && field->width > 1)
		s2 = ft_activate_minus(field, s1, 1);
	else if (field->width > 1)
		s2 = ft_activate_width(field, s1, 1);
	else
	{
		write(1, "%", 1);
		return (1);
	}
	n = ft_putstr(s2, ft_strlen(s2));
	free(s2);
	return (n);
}

char	*conditions_conv_for_u(char *s1, t_field *field)
{
	int				n;
	char			*s2;
	char			*s;

	if (field->flags.minus == 1 && field->width > ft_strlen(s1)
			&& field->precision <= ft_strlen(s1))
		s2 = ft_activate_minus(field, s1, ft_strlen(s1));
	else if ((n = field->precision - 1) >= ft_strlen(s1) && field->width > n)
	{
		field->flags.zero = 0;
		s = ft_strndup_width_x(s1, n);
		if (field->flags.minus == 1)
			s2 = ft_activate_minus(field, s, ft_strlen(s));
		else
			s2 = ft_activate_width(field, s, ft_strlen(s));
		free(s);
	}
	else if (((n = field->precision - 1) > ft_strlen(s1)))
		s2 = ft_strndup_width_x(s1, n);
	else
		return (NULL);
	return (s2);
}

int		ft_u(va_list argptr, t_field *field)
{
	unsigned int	i;
	int				n;
	char			*s1;
	char			*s2;

	i = va_arg(argptr, unsigned int);
	s1 = ft_itoa_u(i);
	s2 = conditions_conv_for_u(s1, field);
	if (((field->precision - 1)) == 0 && i == 0)
		s2 = ft_activate_width_int_zero(field);
	else if (!s2)
	{
		if (((n = field->width) > 0 && n > ft_strlen(s1)))
		{
			if ((n = field->precision - 1) > -1 && n < ft_strlen(s1))
				field->flags.zero = 0;
			s2 = ft_activate_width(field, s1, ft_strlen(s1));
		}
		else
			s2 = ft_strndup(s1, ft_strlen(s1));
	}
	free(s1);
	i = ft_putstr(s2, ft_strlen(s2));
	free(s2);
	return (i);
}
