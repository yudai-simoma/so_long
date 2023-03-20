# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:35:21 by yshimoma          #+#    #+#              #
#    Updated: 2023/03/19 12:28:15 by yshimoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS_DIR = ./src/
SRCS = *.c
OBJ_DIR	=	./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
INCLUDE = header
CC = cc
C_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs

all: ${NAME}

${NAME}:
	${CC} -I${INCLUDE} libmlx.dylib ${SRCS_DIR}${SRCS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
