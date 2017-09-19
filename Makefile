# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 23:06:16 by vle-gal           #+#    #+#              #
#    Updated: 2017/09/19 12:10:26 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c  ft_memmove.c  ft_strcmp.c   ft_strlen.c   ft_strequ.c \
ft_isprint.c ft_memset.c ft_strcpy.c ft_strmap.c   ft_strrchr.c  \
ft_memalloc.c ft_putchar.c ft_strdel.c ft_strncat.c  ft_strsplit.c \
ft_atoi.c ft_memccpy.c ft_putnbr.c ft_strdup.c   ft_strncmp.c  ft_strstr.c \
ft_bzero.c ft_memchr.c ft_putstr.c ft_striter.c  ft_strncpy.c  ft_strsub.c \
ft_isalnum.c ft_memcmp.c ft_strcat.c ft_striteri.c ft_strnew.c   ft_strtrim.c \
ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strjoin.c  ft_strnequ.c   ft_tolower.c \
ft_isascii.c  ft_memdel.c ft_strclr.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strmapi.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_swap.c ft_iterative_power.c \
ft_iterative_factorial.c ft_is_negative.c ft_div_mod.c

OBJDIR = objs

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

############################## COLOR ###########################################

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

############################ REGLES ############################################

all: ${NAME}

${NAME}: ${OBJ}
	@gcc ${FLAGS} -c ${SRC}
	@ar rcs ${NAME} ${OBJ}
	@echo ${Y}Compiling [${NAME}]...${X}
	@echo  ${G}***************${X}

clean:
	@/bin/rm -rf ${OBJ}

fclean: clean
	@/bin/rm -rf ${NAME}

re: fclean all

# lib:
	# make -C libft
