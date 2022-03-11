# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odomenic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 18:41:28 by odomenic          #+#    #+#              #
#    Updated: 2020/12/27 14:14:29 by odomenic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	   ft_extra.c \
	   ft_hex.c \
	   ft_for_parsing.c \
	   ft_width.c \
	   ft_prec.c \
	   ft_write.c \
	   ft_pointer_char.c
OBJ = $(SRCS:.c=.o)
RM = rm -f
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT_A = libft.a

%.o: %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJ}
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_A) $(NAME)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:
	$(RM) $(NAME) $(OBJ)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
