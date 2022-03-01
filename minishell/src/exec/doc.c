/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:25:46 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:25:47 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	here_doc(char *end_mark)
{
	int		pipes[2];
	char	*line;

	pipe(pipes);
	if (is_shell_interactive())
		ft_putstr_fd("> ", 2);
	while (get_next_line(0, &line) == 1 && line && ft_strcmp(line, end_mark))
	{
		write(pipes[1], line, ft_strlen(line));
		write(pipes[1], "\n", 1);
		free(line);
		if (is_shell_interactive())
			ft_putstr_fd("> ", 2);
	}
	close(pipes[1]);
	return (pipes[0]);
}
