/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:43:04 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/06 19:30:43 by lbengoec         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2);
int		strlen_break(char *line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_add_line(char **line, char **previous_line);
char	*cut_line(char **line, char **previous_line, int a);
int		ft_read_file(int fd, char **line, int i);
int		ft_trama(int i, char **read_line, char **line);

#endif

/* ***************************** VARIABLE *********************************** */

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#endif
