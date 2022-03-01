/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:31:14 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:31:16 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	init_signals(void)
{
	signal(SIGINT, (void *)interrupt_blank);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void
	interrupt_line(t_line *line)
{
	if (interrupt_singleton(-1))
	{
		interrupt_singleton(0);
		free(line->line);
		init_line(line);
		g_exit_status = 1;
	}
}
