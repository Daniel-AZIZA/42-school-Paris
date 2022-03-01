/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:27:44 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:27:45 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_append_env(char *name, char *value)
{
	int		split_index;
	char	*var;
	char	*new;

	split_index = value - name;
	name[split_index - 2] = 0;
	var = ft_getenv(name);
	new = ft_strjoin(var, value);
	if (!new)
	{
		ft_setenv(name, value);
		return ;
	}
	ft_setenv(name, new);
	free(new);
}
