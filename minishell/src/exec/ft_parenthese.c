/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parenthese.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:26:09 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:26:11 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "tokenizer.h"
#include "vector.h"

int
	exec_parenthesis(t_command *cmd)
{
	extern char	**environ;

	if (redirect_command(cmd) < 0)
		return (-1);
	return (builtin_parenthesis(cmd->argv, environ));
}

int
	is_cmd_parenthesis(t_command *cmd)
{
	return (!ft_strcmp(PARENTHESIS_OPEN, cmd->cmd));
}
