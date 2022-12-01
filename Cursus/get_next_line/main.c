/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:19 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/01 12:38:17 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int fd;
	char *line;

	fd = open ("fsoares/one_line_no_nl.txt", O_RDONLY);
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
