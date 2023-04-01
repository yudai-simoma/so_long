# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/04/01 14:10:54 by yshimoma         ###   ########.fr        #
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
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C libft
	$(MAKE) -C get_next_line
	$(MAKE) -C ft_printf
	$(MAKE) -C minilibx_mms_20200219
	cp minilibx_mms_20200219/libmlx.dylib ./
	${CC} -g -I${INCLUDE} libmlx.dylib libft/libft.a ft_printf/libftprintf.a get_next_line/get_next_line.a ${OBJS} -o $@

${OBJ_DIR}/%.o:%.c
	mkdir -p ./obj
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
