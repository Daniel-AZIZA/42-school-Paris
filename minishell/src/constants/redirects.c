/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:23:29 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:23:31 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char
	**redirects(void)
{
	static char *arr[] = {REDIR_REPLACE, REDIR_APPEND, REDIR_INPUT,
	REDIR_HERE_DOC, NULL};

	return (arr);
}

char
	**output_redirects(void)
{
	static char *arr[] = {REDIR_REPLACE, REDIR_APPEND, NULL};

	return (arr);
}

char
	**input_redirects(void)
{
	static char *arr[] = {REDIR_INPUT, REDIR_HERE_DOC, NULL};

	return (arr);
}
