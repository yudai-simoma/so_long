# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/30 19:57:00 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS_DIR = ./src
SRCS = main.c map_str.c key_hook.c map_put_img.c error_check.c error_check_utils.c dfs.c stack.c
vpath %.c ${SRCS_DIR}
OBJ_DIR	= ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INCLUDE = ./header
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(MAKE) -C ft_printf
	${CC} -g -I${INCLUDE} libmlx.dylib libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.a ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ./obj
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
