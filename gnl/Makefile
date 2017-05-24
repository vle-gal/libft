# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/24 18:51:29 by vle-gal           #+#    #+#              #
#    Updated: 2017/05/24 19:19:25 by vle-gal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = badass_gnl

SRC = get_next_line.c badass_main.c

OBJ = $(SRC:.c=.o)

LIBI = -Ilibft

LIB = -Llibft -lft

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: ${NAME}

${NAME}: ${OBJ}
	gcc ${FLAGS} ${LIBI} ${LIB} ${OBJ} -o $@

%.o: %.c get_next_line.h
	gcc ${FLAGS} ${LIBI} -c -o $@ $<

clean:
	/bin/rm -rf ${OBJ}

fclean: clean
	/bin/rm -rf ${NAME}

re: fclean all

test: all
	./${NAME} test/vier
	./${NAME} test/vier2
	./${NAME} test/vier3
	./${NAME} test/vier4

code:
	@say WORK LAZY DUMP FUCK
	@banner -w 30 More Work!
