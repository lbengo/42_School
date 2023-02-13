# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/01/24 12:59:16 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME = get_next_line.a

MANDATORY_SRC = get_next_line.c \
				get_next_line_utils.c \

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

INCLUDE = libft.h

CC = gcc
FLAGS = -Wall -Werror -Wextra

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $^

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $^

bonus: $(BONUS_OBJ) $(MANDATORY_OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
