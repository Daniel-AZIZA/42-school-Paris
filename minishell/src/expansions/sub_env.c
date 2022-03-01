/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:28:05 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:28:07 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TO_ESCAPE_ENV "\"\'*"
#include "tokenizer.h"

static size_t
	env_len(char *var)
{
	char	*env;
	size_t	len;

	env = ft_lgetenv(var);
	len = 0;
	if (!env)
		return (0);
	while (*env)
	{
		if (ft_indexof(TO_ESCAPE_ENV, *env) != -1)
			len++;
		len++;
		env++;
	}
	return (len);
}

static size_t
	sub_env(char *dst, char **src)
{
	char	*var;
	size_t	len;

	++(*src);
	var = ft_lgetenv(*src);
	len = env_len(*src);
	while (ft_isalnum(**src) || **src == '_')
		++(*src);
	if (!var)
		return (0);
	while (*var)
	{
		if (ft_indexof(TO_ESCAPE_ENV, *var) != -1)
			*dst++ = '\\';
		*dst++ = *var++;
	}
	return (len);
}

static void
	sub_envs(char *dst, char *src)
{
	while (*src)
	{
		if (*src == '\'')
		{
			*dst++ = *src++;
			while (*src && *src != '\'')
				*dst++ = *src++;
		}
		else if (*src == '\\')
			*dst++ = *src++;
		else if (*src == '$')
			dst += sub_env(dst, &src);
		if (*src)
			*dst++ = *src++;
	}
	*dst = 0;
}

static size_t
	len_with_env(char *line)
{
	size_t len;

	len = ft_strlen(line);
	while (*line)
	{
		if (*line == '\'')
			while (*++line && *line != '\'')
				;
		else if (*line == '$')
			len += env_len(line + 1);
		line++;
	}
	return (len);
}

char
	*parse_variables(char *line)
{
	char *out;

	out = malloc(sizeof(char) * (len_with_env(line) + 1));
	sub_envs(out, line);
	return (out);
}
