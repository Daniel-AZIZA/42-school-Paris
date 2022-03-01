/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:12:21 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:12:23 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void
	free_vector(t_vector *vector)
{
	free(vector->bytes);
	free(vector);
}

void
	*vector_at(t_vector *vector, size_t index)
{
	return (vector->bytes + index * vector->obj_size);
}

void
	*vector_end(t_vector *vector)
{
	return (vector->bytes + vector->len * vector->obj_size);
}
