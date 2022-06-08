# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:50:52 by avillar           #+#    #+#              #
#    Updated: 2022/06/08 12:19:03 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =		push_swap.c			\
			ft_split.c			\
			utils1.c			\
			utils2.c			\
			utils3.c			\
			parsing.c			\
			ft_swap1.c			\
			ft_swap2.c			\
			ft_swap3.c			\
			is_sorted.c			\
			ft_struct.c			\
			ft_struct_utils.c	\
			ft_check_data.c		\
			b_chunk.c			\

CFLAG = -Wall -Wextra -Werror

FSAN = -g -fsanitize=address

OBJS = $(addprefix src/, ${SRCS:.c=.o})

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
