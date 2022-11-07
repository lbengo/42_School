# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 18:52:02 by lbengoec          #+#    #+#              #
#    Updated: 2022/11/07 13:16:28 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME = libftprintf.a

MANDATORY_SRC = ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnbr_10.c \
				ft_putnbr_16_10u.c \
				ft_putpointer.c \

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUDE = ft_printf.h \
			libft.h \

CC = gcc
FLAGS = -Wall -Werror -Wextra

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $^

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	cp libft.a $(NAME)
	ar rcs $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
