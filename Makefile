# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:50:52 by avillar           #+#    #+#              #
#    Updated: 2022/06/03 11:38:22 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =		push_swap.c		\
			ft_split.c		\
			utils1.c		\
			utils2.c		\
			utils3.c		\
			utils4.c		\
			parsing.c		\
			ft_swap1.c		\
			ft_swap2.c		\
			ft_swap3.c		\
			algo_utils1.c	\
			algo_utils2.c	\
			algo_utils3.c	\

SRC	=		test.c			\
			ft_split.c		\
			utils1.c		\
			utils2.c		\
			utils3.c		\
			is_sorted.c		\
			parsing.c		\
			ft_swap1.c		\
			ft_swap2.c		\
			ft_swap3.c		\
			algo_utils1.c	\
			algo_utils2.c	\
			algo_utils3.c	\
			ecart.c			\
			chunk_data.c	\
			chunk_push.c	\
			find_near.c		\
			chunk_sort.c	\

CFLAG = -Wall -Wextra -Werror

FSAN = -g3 -fsanitize=address

OBJS = $(addprefix src/, ${SRC:.c=.o})

CC	= gcc

all: ft_printf/libprintf.a ${NAME}

.c.o:
	$(CC) $(CFLAG) -Ift_printf -c -I/include/includes.h $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -Lft_printf -lprintf -o $(NAME)

ft_printf/libprintf.a:
	make -C ft_printf

clean:
		rm -f ${OBJS}

fclean:	clean
	make -C ft_printf fclean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
