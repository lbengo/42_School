# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/02/28 12:21:43 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME          = so_long

CC            = gcc
CFLAGS         = -Wall -Werror -Wextra

SRC_PATH      = ./src
SRC           = so_long.c \
				create_map.c \
				check_error.c \
				check_error_utils.c \
				texture.c \
				move.c \
				move_utils.c \
				ghost.c

OBJ_PATH      = ./obj
OBJ           = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

INCLUDE       = ./src/so_long.h

MLX_H         = -L minilibx -lmlx -framework OpenGL -framework AppKit

GNL_PATH      = ./get_next_line
GNL_A         = $(GNL_PATH)/get_next_line.a

PRINTF_PATH      = ./ft_printf
PRINTF_A         = $(PRINTF_PATH)/ft_printf.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)

$(NAME): $(OBJ)
	make -C get_next_line
	make -C ft_printf
	make -C minilibx
	$(CC) $^ $(GNL_A) $(PRINTF_A) $(MLX_H) -o $@

bonus: $(OBJ)
	make -C get_next_line
	make -C ft_printf
	make -C minilibx
	$(CC) $^ $(GNL_A) $(PRINTF_A) $(MLX_H) -o $@

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	make -C $(GNL_PATH) clean
	make -C $(PRINTF_PATH) clean

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
