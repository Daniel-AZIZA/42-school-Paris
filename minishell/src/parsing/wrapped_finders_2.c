/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_finders_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:30:53 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:30:55 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int
	is_redirect(char *token)
{
	return ((int)find_token(token, redirects()));
}

int
	is_connective(char *token)
{
	return ((int)find_token(token, connectives()));
}

int
	is_sep(char *token)
{
	return ((int)find_token(token, separators()));
}

int
	is_pipeline_sep(char *token)
{
	return ((int)find_token(token, pipeline_separators()));
}
