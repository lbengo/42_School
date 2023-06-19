# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 09:43:45 by lbengoec          #+#    #+#              #
#    Updated: 2023/06/14 22:47:33 by laurabengoe      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME              = philo

CC                = gcc
CFLAGS            = -Wall -Werror -Wextra -pthread -g3 -fsanitize=address

INCLUDE           = ./include

SRC_PATH          = ./src
SRC               = philo.c \
					check_error.c \
					philo_utils.c \
					thread.c \
					routine.c

OBJ_PATH          = ./obj
OBJ               = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

# ********************************* REGLAS *********************************** #

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_PATH):
	mkdir $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: bonus clean fclean all leaks re