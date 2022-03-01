/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:33:11 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:33:13 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void
	get_term_size(int *width_ptr, int *height_ptr)
{
	struct winsize	ws;
	int				width;
	int				height;

	if (ioctl(0, TIOCGWINSZ, &ws) == 0)
	{
		width = ws.ws_col;
		height = ws.ws_row;
	}
	else
	{
		width = -1;
		height = -1;
	}
	if (width_ptr)
		*width_ptr = width;
	if (height_ptr)
		*height_ptr = height;
}

int
	get_term_width(void)
{
	int	width;

	get_term_size(&width, NULL);
	return (width);
}

int
	get_term_height(void)
{
	int	height;

	get_term_size(NULL, &height);
	return (height);
}
