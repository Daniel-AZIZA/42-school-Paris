# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 19:48:42 by daziza            #+#    #+#              #
#    Updated: 2021/03/13 19:48:46 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s			\
	ft_strcpy.s			\
	ft_strcmp.s			\
	ft_strdup.s			\
	ft_write.s			\
	ft_read.s	

CC = nasm -felf64

OBJS = ${SRCS:.s=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

.s.o:
	${CC} -o $@ $?

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all
