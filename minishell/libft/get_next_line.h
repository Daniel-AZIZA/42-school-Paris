/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:20:52 by daziza            #+#    #+#             */
/*   Updated: 2021/05/16 20:20:53 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_gnl_list
{
	int					fd;
	char				*rest;
	struct s_gnl_list	*next;
}					t_gnl_list;

void				free_null(void	**ptr);
int					get_next_line(int fd, char **line);
size_t				my_strlcpy(char *dest, const char *src, size_t dstsize);
char				*my_strdup(const char *s1);
size_t				my_strlen(const char *str);
char				*gnl_ft_strndup(const char *s4, long long n);
char				*my_strjoin(char *s1, char *s2);
#endif
