/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:41:35 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:41:37 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void		*ft_memdup(void *src, unsigned size)
{
	void		*dest;
	unsigned	i;

	if (!(dest = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

void		*ft_memjoin(char *m1, unsigned s1, char *m2, unsigned s2)
{
	char		*ret;
	unsigned	i;

	if (!m1 || !m2)
		return (NULL);
	if (!(ret = malloc(s1 + s2)))
		return (NULL);
	i = 0;
	while (i < s1)
	{
		ret[i] = m1[i];
		++i;
	}
	i = 0;
	while (i < s2)
	{
		ret[s1 + i] = m2[i];
		++i;
	}
	return (ret);
}

int			get_operation(char ***operation, int ret,
		int total_size)
{
	char		*file;
	char		*tmp;
	char		buf[5];

	file = NULL;
	while ((ret = read(0, buf, 5)) > 0)
	{
		if (ret == -1)
			return (1);
		if (!file)
			file = ft_memdup(buf, ret);
		else
		{
			tmp = file;
			file = ft_memjoin(file, total_size, buf, ret);
			free(tmp);
		}
		total_size += ret;
	}
	if (file)
	{
		*operation = ft_split(file, '\n');
		free(file);
	}
	return (0);
}
