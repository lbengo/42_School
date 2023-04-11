# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:48:35 by lbengoec          #+#    #+#              #
#    Updated: 2023/04/11 17:30:06 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME          = push_swap
CC            = gcc
#CC            = gcc -fsanitize=address
CFLAGS        = -Wall -Werror -Wextra

SRC_PATH      = ./src
SRC           = push_swap.c \
				list_functions.c \
				create_lst.c \
				check_error.c \
				game_rules/swap.c \
				game_rules/push.c \
				game_rules/rotate.c \
				game_rules/reverse_rotate.c \
				algorithm/algorithm.c \
				algorithm/small_algorithm.c \
				algorithm/algorithm_utils.c

OBJ_PATH       = ./obj
OBJ            = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))


LIBFT_PATH       = ./libft
LIBFT_A          = $(LIBFT_PATH)/libft.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ $(LIBFT_A) -o $@

$(OBJ_PATH):
	mkdir $@
	mkdir obj/game_rules
	mkdir obj/algorithm

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: clean fclean all re bonus
