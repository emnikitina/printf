# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odomenic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 18:41:28 by odomenic          #+#    #+#              #
#    Updated: 2020/11/23 20:08:36 by odomenic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_isprint.c	ft_putchar_fd.c	ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c 
OBJ = ${SRCS:%.c=%.o}
RM = rm -f
NAME = libft.a

%.o: %.c libft.h
	${CC} ${FLAGS} -c $< -o ${<:%.c=%.o}

$(NAME): ${OBJ} 
	ar rc ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean:
	${RM} ${NAME} ${OBJ}

re: fclean all
