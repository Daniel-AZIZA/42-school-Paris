/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:57 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:25:59 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void
	close_cmd(t_command *cmd)
{
	close_checked(cmd->fd_input);
	close_checked(cmd->fd_output);
}

void
	close_all_cmds(t_list *commands, t_command *avoid)
{
	t_list	*current;

	current = commands;
	while (current)
	{
		if (avoid != current->content)
			close_cmd(current->content);
		current = current->next;
	}
}
