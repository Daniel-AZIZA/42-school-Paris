/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:27:17 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:27:19 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int
	check_escape(char *current, char *quote)
{
	return (
		(*quote == '"' && ft_indexof(DQ_ESCAPES "\\", *current) != -1)
		|| (*quote == '\'' && ft_indexof(SQ_ESCAPES, *current) != -1)
		|| (!*quote && current[0] == SPACE && current[-1] == '\\'));
}
