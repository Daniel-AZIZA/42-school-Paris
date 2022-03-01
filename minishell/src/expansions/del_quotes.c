/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:27:28 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:27:30 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

char
	*remove_quotes(char *line)
{
	char				*quote;
	int					escaped;
	char				*new;
	unsigned int		flag;
	size_t				i;

	quote = "\0";
	escaped = 0;
	if (!(new = ft_calloc(ft_strlen(line) + 1, 1)))
		return (NULL);
	i = 0;
	while (*line)
	{
		flag = 0 | (*quote != '\'' && *line == '\\' && !escaped) | (escaped &&
		*line == '\\') << 1 | (!escaped && !*quote && ft_strchr("\"'", *line))
		<< 2 | (!escaped && *line == *quote) << 3;
		quote = (char *)((size_t)quote * (!(flag & 0b100) && !(flag & 0b1000))
		+ (size_t)line * !!(flag & 0b100) + (size_t)"\0" * !!(flag & 0b1000));
		escaped = (*quote != '\'' && *line == '\\' && !escaped);
		if ((!(flag & 0b100) * !(flag & 0b1000)) * (!(flag & 0b10) || !*quote)
		* (!(flag & 0b1) || (*quote && !ft_strchr("\"$`", line[1]))))
			new[i++] = *line;
		++line;
	}
	return (new);
}
