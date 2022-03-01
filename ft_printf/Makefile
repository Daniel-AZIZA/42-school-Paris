# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daziza <daziza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 13:37:07 by daziza            #+#    #+#              #
#    Updated: 2020/12/10 13:37:09 by daziza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS 		= ft_printf.c ft_flags.c ft_conv_pxx.c  ft_itoa.c ft_tools_hexa.c ft_conv_sc.c ft_conv_upourcent.c ft_global_tools.c ft_tools_digit.c ft_all_strdup.c ft_parsing.c ft_conv_id.c ft_flags_hexa.c

OBJS 		= ${SRCS:.c=.o}

CC		= gcc

CFLAGS		= -Wall -Wextra -Werror -Iincludes

RM		= rm -f

all :		${NAME}

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
 
$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean :
		${RM} ${OBJS} ${DEP}

test: ${NAME}
		gcc main.c $< -o ft_printf -Wno-format -fsanitize=address
		./ft_printf 1>MOI 2>DEBUG 3>ORIGI
		diff --text MOI ORIGI | cat -e 

fclean : 	clean
		${RM} ${NAME}
		${RM} ft_printf

re : 		fclean all

.PHONY : 	all bonus clean fclean re
