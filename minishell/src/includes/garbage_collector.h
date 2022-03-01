/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:12:53 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:12:56 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include "structs.h"
# include <stdlib.h>
# include "libft.h"
# include "termcaps.h"

void	free_line(t_line *line);
void	free_to_null(void **ptr);
void	free_tokens(char **tokens);
void	free_cmd(t_command *cmd);
void	free_ast_node(t_ast_node *node);
void	free_ast(t_ast ast);
void	free_pipeline(t_pipeline *pipeline);

#endif
