/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:00:42 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/15 11:43:46 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
# include <unistd.h> // Librería que gestiona la función close
# include <stdio.h>
# include <fcntl.h> // Librería que gestiona la función open
#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#endif

int main (void)
{
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t leidos;

	fd = open ("foo.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("fd = %d\n", fd);
	leidos = read(fd, buffer, BUFFER_SIZE);
	close(fd);
	printf("Número de carácteres = %zd y contenido = %s", leidos, buffer);
	return (0);
}


