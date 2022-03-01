/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:23:48 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:24:02 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

char
	**g_capstr(void)
{
	static char *array[] = {
	"kl",
	"kr",
	"#4",
	"%i",
	"#4",
	"#4",
	"kh",
	"@7",
	"ku"
	};

	return (array);
}

t_cap
	*g_caps(void)
{
	static t_cap	array[] = {
		move_left,
		move_right,
		prev_word,
		next_word,
		move_down,
		move_up,
		go_home,
		go_end,
		retreive_hist
	};

	return (array);
}
