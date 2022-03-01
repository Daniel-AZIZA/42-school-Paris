/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:22:22 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:22:24 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

int	builtin_pwd(char **av, char **envp)
{
	char	dir[PATH_MAX];

	(void)av;
	(void)envp;
	if (!getcwd(dir, PATH_MAX))
		return (handle_error("minishell: pwd:", NULL, NULL));
	ft_putendl_fd(dir, 1);
	return (0);
}
