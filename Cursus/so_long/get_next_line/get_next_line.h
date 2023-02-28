/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:43:04 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 12:16:33 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ***************************** LIBRERIAS ********************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/* ***************************** FUNCIONES ********************************** */

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		strlen_break(char *line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ***************************** VARIABLE *********************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
