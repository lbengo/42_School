# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:52:02 by lbengoec          #+#    #+#              #
#    Updated: 2023/02/26 13:51:20 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME = libftprintf.a

MANDATORY_SRC = ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnbr_10.c \
				ft_putnbr_10_u.c \
				ft_putnbr_16.c \
				ft_putpointer.c \
				ft_strlen.c \

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

INCLUDE = ft_printf.h

CC = gcc
FLAGS = -Wall -Werror -Wextra

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $^

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
