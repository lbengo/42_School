/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:43:04 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/15 21:55:33 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ***************************** LIBRERIAS ********************************** */

# include <unistd.h> // Librería que gestiona la función close
# include <fcntl.h> // Librería que gestiona la función open
# include <stdio.h>
#include <stdlib.h>

/* ***************************** FUNCIONES ********************************** */

char	*get_next_line(int fd);
int		ft_putstr(char *s);

#endif

/* ***************************** VARIABLE *********************************** */

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#endif
