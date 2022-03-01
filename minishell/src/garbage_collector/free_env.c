/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:28:38 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:28:39 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void
	free_env(void)
{
	extern char	**environ;
	char		**current;

	if (!environ)
		return ;
	current = environ;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(environ);
}
