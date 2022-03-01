/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:23:36 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:23:38 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char
	**separators(void)
{
	static char *arr[] = (char *[]){PIPE, SEMICOLON, NULL};

	return (arr);
}

char
	**pipeline_separators(void)
{
	static char *arr[] = {SEMICOLON, AND, OR, NULL};

	return (arr);
}

char
	**connectives(void)
{
	static char *arr[] = {PIPE, AND, OR, REDIR_APPEND, REDIR_REPLACE,
	REDIR_INPUT, REDIR_HERE_DOC, NULL};

	return (arr);
}

char
	**token_separators(void)
{
	static char *arr[] = {OR, PIPE, SEMICOLON, AND, AMPERSAND, PARENTHESIS_OPEN,
	PARENTHESIS_CLOSE, NULL};

	return (arr);
}
