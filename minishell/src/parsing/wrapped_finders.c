/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_finders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:30:59 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:31:01 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char
	**find_sep(char **tokens)
{
	return (find_token_in_tokens(tokens, separators()));
}

char
	**find_pipe(char **tokens)
{
	return (safe_find_token(tokens, PIPE));
}

size_t
	get_pipeline_len(char **tokens)
{
	return (find_token_in_tokens(tokens, pipeline_separators()) - tokens);
}
