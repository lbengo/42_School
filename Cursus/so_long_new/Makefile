# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/02/14 14:08:12 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gcc src/so_long.c src/check_error.c src/create_map.c src/check_error_utils.c -L minilibx get_next_line/get_next_line.a -lmlx -framework OpenGL -framework AppKit -g3

# ********************************* VARIABLES ******************************** #

NAME          = so_long

CC            = gcc
CFLAGS         = -Wall -Werror -Wextra

SRC_PATH      = ./src
SRC           = so_long.c \
				create_map.c \
				check_error.c \
				check_error_utils.c

OBJ_PATH      = ./obj
OBJ           = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

INCLUDE       = ./src/so_long.h

MLX_H         = -L minilibx -lmlx -framework OpenGL -framework AppKit

GNL_PATH      = ./get_next_line
GNL_A         = $(GNL_PATH)/get_next_line.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(GNL_A) $(MLX_H) -o $@

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
