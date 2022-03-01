/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:05:48 by daziza            #+#    #+#             */
/*   Updated: 2020/11/21 16:04:52 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(unsigned char *s1, unsigned char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		else
			i++;
	}
	return (0);
}
