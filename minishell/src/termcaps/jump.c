/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:32:38 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:32:39 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	prev_word(t_line *line)
{
	size_t pos;

	move_left(line);
	pos = line->r_cur_pos;
	while (*line->line && !ft_isalnum(line->line[pos]) && pos > 0)
		pos--;
	while (ft_isalnum(line->line[pos]) && pos > 0)
		pos--;
	line->start_column = get_start_column(line);
	line->cursor_pos.x = (pos + ft_strlen(prompt())) % get_term_width() + !!pos;
	line->r_cur_pos = pos;
	line->cursor_pos.y = line->start_column + get_line_height(pos);
	move_cursor(line->cursor_pos.x, line->cursor_pos.y);
}

void	next_word(t_line *line)
{
	size_t pos;

	move_right(line);
	pos = line->r_cur_pos;
	while (ft_isalnum(line->line[pos]) && pos < line->len)
		pos++;
	while (*line->line && !ft_isalnum(line->line[pos]) && pos < line->len)
		pos++;
	line->start_column = get_start_column(line);
	line->cursor_pos.x = (pos + ft_strlen(prompt())) % get_term_width()
	- (pos != line->len);
	line->r_cur_pos = pos;
	line->cursor_pos.y = line->start_column + get_line_height(pos);
	move_cursor(line->cursor_pos.x, line->cursor_pos.y);
}
