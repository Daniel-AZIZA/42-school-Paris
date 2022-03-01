/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:21:47 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:21:50 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUILTIN_COUNT 8

static const t_builtin g_builtins[BUILTIN_COUNT + 1] = {
	builtin_echo,
	builtin_exit,
	builtin_cd,
	builtin_env,
	builtin_pwd,
	builtin_unset,
	builtin_export,
	builtin_parenthesis,
	NULL
};

static const char *g_builtin_list[BUILTIN_COUNT + 1] = {
	"echo",
	"exit",
	"cd",
	"env",
	"pwd",
	"unset",
	"export",
	"(",
	NULL
};

int
	is_builtin(char *command)
{
	int i;

	i = -1;
	while (g_builtin_list[++i])
		if (!ft_strcmp(g_builtin_list[i], command))
			return (i);
	return (-1);
}

int
	exec_builtin(char **av, char **envp)
{
	int i;

	i = is_builtin(*av);
	if (i == -1)
		return (-1);
	return (g_builtins[i](av, envp));
}
