/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:35:47 by daziza            #+#    #+#             */
/*   Updated: 2020/12/10 13:35:48 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parsing(const char *format, t_field *field, va_list argptr, int i)
{
	const char *tmp_f;

	while (format[i] && ft_flag_valide(format[i], field) == 2)
	{
		if (format[i] == '.' && format[i + 1] == '*')
		{
			field->precision = va_arg(argptr, int) + 1;
			i += 1;
		}
		else if (format[i] == '.' && format[i + 1] != '*')
		{
			i += 1;
			tmp_f = format + i;
			while (ft_isdigit(format[i]) == 1)
				i++;
			field->precision = ft_atoi(tmp_f, i) + 1;
			i--;
		}
		else if (format[i] == '*' && field->precision == -1
				&& field->width == 0)
			field->width = va_arg(argptr, int);
		ft_check_neg(field);
		i++;
	}
	return (i);
}

int		ft_abs(int n)
{
	return ((n < 0) ? (-n) : (n));
}

void	ft_check_neg(t_field *field)
{
	if ((field->precision - 1) < -1)
		field->precision = -1;
	if (field->width < 0)
	{
		field->flags.minus = 1;
		field->width = ft_abs(field->width);
	}
	if ((field->precision - 1) == 0)
		field->flags.zero = 0;
}
