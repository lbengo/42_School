# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:48:35 by lbengoec          #+#    #+#              #
#    Updated: 2023/05/27 18:52:49 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME              = pipex
BONUS             = pipex_bonus

CC                = gcc
CFLAGS            = -Wall -Werror -Wextra -g3 -fsanitize=address

INCLUDE           = ./include

SRC_PATH          = ./src
SRC               = pipex.c \
					pipex_utils.c \
					check_error.c

SRC_BONUS_PATH    = ./src_bonus
SRC_BONUS         = pipex.c \
					pipex_utils.c \
					check_error.c \
					file_in.c \
					file_out.c



OBJ_PATH          = ./obj
OBJ               = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

OBJ_BONUS_PATH    = ./obj_bonus
OBJ_BONUS         = $(addprefix $(OBJ_BONUS_PATH)/, $(SRC_BONUS:.c=.o))

LIBFT_PATH        = ./src/libft
LIBFT_A           = $(LIBFT_PATH)/libft.a

LIBFT_BONUS_PATH  = ./src_bonus/libft
LIBFT_BONUS_A     = $(LIBFT_BONUS_PATH)/libft.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c | $(OBJ_BONUS_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

# ********************************* REGLAS *********************************** #

#.SILENT:

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
END=\033[0m

define PIPEX

$(WHITE)╔╦╗$(RED)╦ ╦ $(YELLOW)╔═╗    $(GREEN)╔═╗ $(CYAN)╦ $(BLUE)╔═╗ $(MAG)╔═╗ $(WHITE)╔═╗
$(WHITE) ║ $(RED)╠═╣ $(YELLOW)║╣     $(GREEN)╠═╝ $(CYAN)║ $(BLUE)╠═╝ $(MAG)║╣  $(WHITE)╚═╗
$(WHITE) ╩ $(RED)╩ ╩ $(YELLOW)╚═╝    $(GREEN)╩   $(CYAN)╩ $(BLUE)╩   $(MAG)╚═╝ $(WHITE)╚═╝$(END)

endef
export PIPEX

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $^ $(LIBFT_A) -o $@
	echo "$$PIPEX"

bonus: $(BONUS)
$(BONUS): $(OBJ_BONUS)
	make -C $(LIBFT_BONUS_PATH)
	$(CC) $(CFLAGS) $^ $(LIBFT_BONUS_A) -o pipex_bonus
	echo "$$PIPEX"

$(OBJ_PATH):
	mkdir $@

$(OBJ_BONUS_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(OBJ_BONUS_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(LIBFT_BONUS_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	make -C $(LIBFT_PATH) fclean
	make -C $(LIBFT_BONUS_PATH) fclean

re:	fclean all

.PHONY: bonus clean fclean all leaks re
