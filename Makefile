# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/20 20:35:52 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS_DIR = ./src/
SRCS = *.c
OBJ_DIR	=	./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INCLUDE = ./header
CC = cc
C_FLAGS = -Wall -Wextra #-Werror
AR = ar
AR_FLAGS = rcs

all: ${NAME}

${NAME}:
	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(MAKE) -C ft_printf
	${CC} -I${INCLUDE} libmlx.dylib libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.a ${SRCS_DIR}${SRCS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
