/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:33:53 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:33:55 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"
#include <errno.h>
#include <string.h>

int
	handle_error(char *command, char *arg, char *errmsg)
{
	int err;

	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (errmsg)
		ft_putendl_fd(errmsg, 2);
	else
		ft_putendl_fd(strerror(errno), 2);
	err = errno;
	errno = 0;
	return (err);
}

void
	print_file_error(char *filename)
{
	ft_putstr_fd(SHELL_NAME " : ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	if (filename)
		ft_putendl_fd(filename, 2);
}
