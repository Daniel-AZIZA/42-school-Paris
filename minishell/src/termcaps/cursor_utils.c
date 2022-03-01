/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:31:44 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:31:46 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include <errno.h>
#include <string.h>

void
	get_cursor(t_point *cursor)
{
	char	cursor_pos[17];
	size_t	i;
	int		rd;

	write(0, CURSOR_QUERY, 4);
	rd = read(1, cursor_pos, 16);
	if (rd < 0)
	{
		ft_perror("minishell");
		exit(errno);
	}
	cursor_pos[rd] = '\0';
	i = 2;
	cursor->y = ft_atoi(cursor_pos + i) - 1;
	while (ft_isdigit(cursor_pos[i]))
		i++;
	cursor->x = ft_atoi(cursor_pos + i + 1) - 1;
}

void
	locate_cursor(t_line *line)
{
	int		term_width;
	size_t	prompt_len;

	prompt_len = ft_strlen(prompt());
	term_width = get_term_width();
	line->cursor_pos.x = (line->r_cur_pos + prompt_len) % (term_width - 1);
	line->cursor_pos.y += (line->r_cur_pos + prompt_len) / (term_width - 1);
}

void
	update_cursor(t_line *line)
{
	move_cursor(line->cursor_pos.x, line->cursor_pos.y);
}
