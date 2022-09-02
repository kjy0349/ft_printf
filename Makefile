# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 16:31:45 by jeykim            #+#    #+#              #
#    Updated: 2022/09/02 11:57:48 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_printf.c print_strnum.c print_uhex.c
OBJECT	= ${SRC:.c=.o}
INCS	= .

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJECT}
	ar rc $@ $^

all : ${NAME}

clean :
	rm -f ${OBJECT} ${OBJECT_BONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re .c.o