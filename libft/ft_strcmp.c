/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:41:59 by daziza            #+#    #+#             */
/*   Updated: 2021/04/05 18:44:07 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(unsigned char *s1, unsigned char *s2)
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
	return (0);
}
