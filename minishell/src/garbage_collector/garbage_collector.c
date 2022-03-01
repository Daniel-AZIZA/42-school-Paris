/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:28:43 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:28:46 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void
	free_to_null(void **ptr)
{
	if (!ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void
	free_tokens(char **tokens)
{
	char **current;

	current = tokens;
	if (!current)
		return ;
	while (*current)
	{
		free(*current);
		*current = NULL;
		current++;
	}
	free(tokens);
}

void
	free_cmd(t_command *cmd)
{
	if (cmd->cmd != cmd->argv[0])
		free(cmd->cmd);
	free_tokens(cmd->argv);
	cmd->argv = NULL;
	free_to_null((void **)&(cmd->sep));
	free_tokens(cmd->tokens);
	cmd->tokens = NULL;
	free_tokens(cmd->redirections);
	cmd->redirections = NULL;
	free(cmd);
}

void
	free_pipeline(t_pipeline *pipeline)
{
	ft_lstclear(pipeline, (void *)free_cmd);
}

void
	free_line(t_line *line)
{
	free(line->line);
	free(line);
}
