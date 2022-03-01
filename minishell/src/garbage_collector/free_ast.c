/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:28:32 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:28:34 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void
	free_ast_node(t_ast_node *node)
{
	free_tokens(node->abstract_pipeline);
	node->abstract_pipeline = NULL;
	free_pipeline(&(node->pipeline));
	free_to_null((void **)&node->sep);
	free(node);
}

void
	free_ast(t_ast ast)
{
	ft_lstclear(&ast, (void *)free_ast_node);
}
