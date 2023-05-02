# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:48:35 by lbengoec          #+#    #+#              #
#    Updated: 2023/04/19 17:25:34 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME          = pipex
CC            = gcc
CFLAGS        = -Wall -Werror -Wextra

INCLUDE       = ./include

SRC_PATH      = ./src
SRC           = pipex.c

OBJ_PATH       = ./obj
OBJ            = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIBFT_PATH       = ./src/libft
LIBFT_A          = $(LIBFT_PATH)/libft.a

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $^ $(LIBFT_A) -o $@

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: clean fclean all re