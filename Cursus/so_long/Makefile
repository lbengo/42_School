# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/05/19 21:34:15 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME          = so_long
BONUS         = so_long_bonus
CC            = gcc
CFLAGS        = -Wall -Werror -Wextra

SRC_PATH      = ./src
SRC           = so_long.c \
				create_map.c \
				check_error.c \
				check_error_utils.c \
				texture.c \
				move.c \
				move_utils.c

SRC_BONUS_PATH = ./src_bonus
SRC_BONUS      = so_long.c \
				create_map.c \
				check_error.c \
				check_error_utils.c \
				texture.c \
				move.c \
				move_utils.c \
				ghost.c

OBJ_PATH       = ./obj
OBJ            = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

OBJ_BONUS_PATH = ./obj_bonus
OBJ_BONUS      = $(addprefix $(OBJ_BONUS_PATH)/, $(SRC_BONUS:.c=.o))

MLX_PATH       = ./functions/minilibx
MLX_H          = -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

GNL_PATH       = ./functions/get_next_line
GNL_A          = $(GNL_PATH)/get_next_line.a

PRINTF_PATH    = ./functions/ft_printf
PRINTF_A       = $(PRINTF_PATH)/ft_printf.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(OBJ_BONUS_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(GNL_PATH)
	make -C $(PRINTF_PATH)
	make -C $(MLX_PATH)
	$(CC) $^ $(GNL_A) $(PRINTF_A) $(MLX_H) -o $@

bonus: $(BONUS)
$(BONUS): $(OBJ_BONUS)
	make -C $(GNL_PATH)
	make -C $(PRINTF_PATH)
	make -C $(MLX_PATH)
	$(CC) $^ $(GNL_A) $(PRINTF_A) $(MLX_H) -o $@

$(OBJ_PATH):
	mkdir $@

$(OBJ_BONUS_PATH):
	echo $@
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_BONUS_PATH)
	make -C $(GNL_PATH) clean
	make -C $(PRINTF_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make -C $(GNL_PATH) fclean
	make -C $(PRINTF_PATH) fclean

re:	fclean all

.PHONY: clean fclean all re bonus
