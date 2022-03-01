/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:42:01 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:42:02 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	check_int_min(char *str)
{
	unsigned int	i;
	char			*int_min;

	i = 0;
	str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	if (i > 10)
		return (1);
	if (i < 10)
		return (0);
	i = 0;
	int_min = "2147483648";
	while (str[i] && int_min[i] && ((str[i] - int_min[i]) <= 0))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

static int	check_int_max(char *str)
{
	unsigned int	i;
	char			*int_max;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	if (i > 10)
		return (1);
	if (i < 10)
		return (0);
	i = 0;
	int_max = "2147483647";
	while (str[i] && int_max[i] && ((str[i] - int_max[i]) <= 0))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

static int	ft_strcmp_modify(unsigned char *s1, unsigned char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		else
			i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

static int	doublon(char **av)
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (av[i])
	{
		tmp = av[i];
		j = i + 1;
		while (av[j])
		{
			if ((ft_strcmp_modify((unsigned char *)tmp,
							(unsigned char *)av[j])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			parsing_arg(char **av, int *flag)
{
	unsigned int	i;

	i = get_flag(av, flag);
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			if (check_int_min(av[i]))
				return (1);
		}
		else
		{
			if (check_int_max(av[i]))
				return (1);
		}
		i++;
	}
	if (doublon(av))
		return (1);
	return (0);
}
