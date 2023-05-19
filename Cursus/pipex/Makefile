# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:48:35 by lbengoec          #+#    #+#              #
#    Updated: 2023/05/19 21:50:24 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME           = pipex
BONUS          = pipex_bonus
CC             = gcc
CFLAGS         = -Wall -Werror -Wextra

INCLUDE        = ./include

SRC_PATH       = ./src
SRC            = pipex.c \
				 pipex_utils.c \
				 check_error.c

SRC_BONUS_PATH = ./src_bonus
SRC_BONUS      = pipex.c \
				 pipex_utils.c \
				 check_error.c

OBJ_PATH       = ./obj
OBJ            = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

OBJ_BONUS_PATH = ./obj_bonus
OBJ_BONUS      = $(addprefix $(OBJ_BONUS_PATH)/, $(SRC_BONUS:.c=.o))

LIBFT_PATH     = ./src/libft
LIBFT_A        = $(LIBFT_PATH)/libft.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(OBJ_BONUS_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ $(LIBFT_A) -o $@

bonus: $(BONUS)
$(BONUS): $(OBJ_BONUS)
	make -C $(LIBFT_PATH)
	$(CC) $^ $(LIBFT_A) -o pipex_bonus

$(OBJ_PATH):
	mkdir $@

$(OBJ_BONUS_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_BONUS_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: bonus clean fclean all leaks re
