/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:30:31 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:30:32 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char
	**dup_n_tab(char **table, size_t n)
{
	char		**dup;
	size_t		size;
	size_t		i;

	size = tab_size(table);
	if (n < size)
		size = n;
	dup = ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		dup[i] = ft_strdup(table[i]);
		i++;
	}
	return (dup);
}

char
	*alloc_path_buf(char *cmd)
{
	(void)cmd;
	return (ft_calloc(ft_strlen(cmd) + PATH_MAX + 1, 1));
}

size_t
	pure_tokens_len(char **tokens, char **excluded_tokens)
{
	char	**current;
	size_t	len;

	current = tokens;
	len = 0;
	while (*current)
	{
		if (find_token(*current, excluded_tokens) == 0)
			len++;
		current++;
	}
	return (len);
}

char
	**ref_in_tokens(char *ref, char **tokens)
{
	if (!ref)
		return (NULL);
	while (*tokens)
	{
		if (ref == *tokens)
			return (tokens);
		tokens++;
	}
	return (NULL);
}

int
	check_path_ptr(char **path_ptr)
{
	return (path_ptr && *path_ptr && path_ptr[1] && !is_sep(path_ptr[1]));
}
