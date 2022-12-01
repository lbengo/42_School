/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:19 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/01 13:09:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int fd;
	char *line;

	fd = open ("hola.txt", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("(%s)\n", line);
		free(line);
		
		/* line = get_next_line(fd);
		printf("(%s)\n", line);
		free(line);
		line = get_next_line(fd);
		printf("(%s)\n", line);
		free(line); */
	}
	close(fd);
	return (0);
}
