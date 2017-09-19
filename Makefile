# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 23:06:16 by vle-gal           #+#    #+#              #
#    Updated: 2017/09/19 18:00:09 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_BASIC = \
ft_isdigit.c  ft_memmove.c  ft_strcmp.c   ft_strlen.c   ft_strequ.c \
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



SRC_PRINTF = \
ft_printfl.c ft_printf_conversion.c ft_printf_long.c \
ft_printf_s.c ft_printf_p.c	ft_printf_d.c \
ft_printf_u.c ft_printf_o.c	ft_printf_x.c \
ft_printf_c.c ft_flags.c \
ft_printf_d_flags.c ft_printf_u_flags.c \
ft_printf_x_flags.c ft_printf_o_flags.c

OBJDIR = objs

OBJ_BASIC = $(addprefix ${OBJDIR}/, $(SRC_BASIC:.c=.o))

OBJ_PRINTF = $(addprefix ${OBJDIR}/, $(SRC_PRINTF:.c=.o))


CFLAGS = -Wall -Wextra -Werror

CC = gcc

LFT = doth/libft.h
FTP = doth/printf.h

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
		@echo ${Y}Success"  "[${NAME}]${X}

${NAME}: ${OBJ_BASIC} ${OBJ_PRINTF}
	@ar rcs ${NAME} ${OBJ_BASIC} ${OBJ_PRINTF}
	@echo ${G}Compiling [${NAME}]...${X}

${OBJDIR}/%.o : ./basic/%.c ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./doth -c -o $@ $<
	@printf ${UP}${CUT}

${OBJDIR}/%.o : ./printf/%.c ${FTP} ${LFT}
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} -I./doth -c -o $@ $<
	@printf ${UP}${CUT}

clean:
	@/bin/rm -rf ${OBJDIR}

fclean: clean
	@/bin/rm -rf ${NAME}

re: fclean all
