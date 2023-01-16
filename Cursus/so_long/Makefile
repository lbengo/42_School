# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/01/16 09:03:48 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc so_long.c -L minilibx -lmlx -framework OpenGL -framework AppKit

# ********************************* VARIABLES ******************************** #

NAME = so_long.a

MANDATORY_SRC = so_long.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

INCLUDE = libft.h

CC = gcc
FLAGS = -Wall -Werror -Wextra -Iminilibx
MINILIBX = -L minilibx -lmlx -framework OpenGL -framework AppKit

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	$(CC) $^ -L minilibx -lmlx -framework OpenGL -framework AppKit $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
