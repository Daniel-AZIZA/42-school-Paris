/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soukamar <soukamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:11:53 by soukamar          #+#    #+#             */
/*   Updated: 2021/05/16 20:11:58 by soukamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "string.h"

typedef struct	s_vector
{
	void	*bytes;
	size_t	len;
	size_t	available;
	size_t	size;
	size_t	obj_size;
}				t_vector;

void			*vect_ft_memset(void *b, int c, size_t len);
void			*vect_ft_memcpy(void *dst, void *src, size_t n);
void			*vect_ft_calloc(size_t count, size_t size);

void			free_vector(t_vector *vector);
t_vector		*new_vector(size_t count, size_t size);
t_vector		*vector_resize(t_vector *vector, size_t new_size);
t_vector		*vector_append(t_vector *vector, void *add, size_t count);
void			vector_iter(t_vector *vector, void (*func)());
void			vector_clear(t_vector *vector, void (*func)());
void			*vector_end(t_vector *vector);
void			*vector_at(t_vector *vector, size_t index);
#endif
