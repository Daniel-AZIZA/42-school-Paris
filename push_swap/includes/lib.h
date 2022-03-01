/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daziza <daziza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:43:53 by daziza            #+#    #+#             */
/*   Updated: 2021/04/19 19:43:55 by daziza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdbool.h>
# include "list.h"

size_t	ft_strlen(char *str, char c);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *str, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
int		get_next_line(int fd, char **line);
bool	ft_equals(char *str1, char *str2);
size_t	getlen(t_item *item);
int		getmin(t_item *item);
int		getmax(t_item *item);
size_t	getindex(t_item *item, int nbr);
ssize_t	getpivot(t_number number, size_t index, size_t division);
#endif
