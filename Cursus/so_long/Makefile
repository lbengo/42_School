# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/01/24 09:39:11 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc so_long.c -L minilibx -lmlx -framework OpenGL -framework AppKit -g3

# ********************************* VARIABLES ******************************** #

NAME = so_long.a

MANDATORY_SRC = so_long.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

INCLUDE = so_long.h

CC = gcc
FLAGS = -Wall -Werror -Wextra
MINILIBX = -L minilibx -lmlx -framework OpenGL -framework AppKit

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $^

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	$(CC) $^ $(MINILIBX) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
