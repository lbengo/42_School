# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 12:52:49 by lbengoec          #+#    #+#              #
#    Updated: 2023/03/30 08:34:55 by lbengoec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************************* VARIABLES ******************************** #

NAME = libft.a

MANDATORY_SRC = ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_split.c \
				ft_free.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

INCLUDE = libft.h

CC = gcc
FLAGS = -Wall -Werror -Wextra

# ******************* REGLAS INTERNAS MODIFICADAS DEL MAKE ******************* #

%.o: %.c
	$(CC) $(FLAGS) -c $^

# ************************* REGLAS PROPIAS DEL MAKE ************************** #

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	ar rcs $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re bonus
