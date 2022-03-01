# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 19:43:36 by daziza            #+#    #+#              #
#    Updated: 2021/04/19 19:43:38 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker
CLEAR		= \033[2K\c
CC			= clang
RM			= rm -rf
OS			= $(shell uname)

CFLAGS		= -O3 -Ofast
IFLAGS		= -I${INC_DIR} -I${LIBFT_DIR}/includes -D LINUX=0
LFLAGS		= -L ${LIBFT_DIR} -lft -Wall -Wextra -Werror	

SRCS_DIR	= ./
INC_DIR		= ../includes
LIBFT_DIR	= ../libft
OBJS_DIR	= ../objs

INC         	= $(shell find ${INC_DIR} -type f -name "*.h")
SRCS 		= $(notdir $(shell find ${SRCS_DIR} -type f -name "*.c"))
OBJS 		= $(addprefix ${OBJS_DIR}/, $(SRCS:.c=.o))
vpath		%.c $(shell find ${SRCS_DIR} -type d)

ifeq (${OS}, Linux)
	IFLAGS  = -I/usr/include -I${INC_DIR} -I${LIBFT_DIR}/includes -D LINUX=1
	LFLAGS  = -L ${LIBFT_DIR} -lft -Wall -Werror -Wextra 
endif 

all: 		init ${NAME}

init:
			$(shell mkdir -p ${OBJS_DIR})
			${MAKE} --silent -C ${LIBFT_DIR}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${IFLAGS} -o $@ $^ ${LFLAGS}

${OBJS_DIR}/%.o:	%.c
			@echo "${CLEAR}"
			@echo "compiling $<\r\c"
			@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS_DIR}
			${MAKE} clean --silent -C ${LIBFT_DIR}

fclean:
			${RM} ${OBJS_DIR}
			${RM} ${NAME}
			${MAKE} fclean --silent -C ${LIBFT_DIR}

re:			fclean all

.SUFFIXES:	.c .o .h
.PHONY:		all clean fclean re

