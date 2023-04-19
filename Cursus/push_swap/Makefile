# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:48:35 by lbengoec          #+#    #+#              #
#    Updated: 2023/04/19 17:18:04 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME          = push_swap
CC            = gcc
CFLAGS        = -Wall -Werror -Wextra

INCLUDE       = ./include

SRC_PATH      = ./src
SRC           = push_swap.c \
				check_error.c \
				create_lst.c \
				movements/swap.c \
				movements/push.c \
				movements/rotate.c \
				movements/reverse_rotate.c \
				algorithm/algorithm.c \
				algorithm/algorithm_utils.c \
				algorithm/cost.c \
				algorithm/big_algorithm.c \
				algorithm/move.c

OBJ_PATH       = ./obj
OBJ            = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIBFT_PATH       = ./src/libft
LIBFT_A          = $(LIBFT_PATH)/libft.a

LIBLST_PATH       = ./src/liblst
LIBLST_A          = $(LIBLST_PATH)/liblst.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	make -C $(LIBLST_PATH)
	$(CC) $^ $(LIBFT_A) $(LIBLST_A) -o $@

$(OBJ_PATH):
	mkdir $@
	mkdir obj/movements
	mkdir obj/algorithm

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBLST_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(LIBLST_PATH) fclean

re:	fclean all

.PHONY: clean fclean all re
