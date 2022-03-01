/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:17:50 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:17:52 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <string.h>

void	ft_perror(const char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(strerror(errno), 2);
}
