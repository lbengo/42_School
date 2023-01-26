# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/01/26 13:33:25 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc so_long.c -L minilibx get_next_line/get_next_line.a -lmlx -framework OpenGL -framework AppKit -g3

# ********************************* VARIABLES ******************************** #

NAME = so_long

MANDATORY_SRC = so_long.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

INCLUDE = so_long.h

CC = gcc
FLAGS = -Wall -Werror -Wextra
MINILIBX = -L minilibx get_next_line/get_next_line.a -lmlx -framework OpenGL -framework AppKit
GETNEXTLINE = get_next_line/get_next_line.a

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
