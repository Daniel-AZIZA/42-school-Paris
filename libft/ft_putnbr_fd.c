/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:01:54 by daziza            #+#    #+#             */
/*   Updated: 2020/11/24 17:19:24 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -n;
	}
	else
		(nbr = n);
	if ((nbr / 10) != 0)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(48 + (nbr % 10), fd);
}
