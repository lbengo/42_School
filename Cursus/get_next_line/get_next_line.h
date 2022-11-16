/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:43:04 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/16 09:33:30 by lbengoec         ###   ########.fr       */
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

char		*get_next_line(int fd);
int			break_status(char *buffer);
char		*send_line(char *buffer);
static char	*end_line(char *s, size_t len);

#endif

/* ***************************** VARIABLE *********************************** */

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
#endif
