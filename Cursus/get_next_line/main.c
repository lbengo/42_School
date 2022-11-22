/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:19 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/22 21:20:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	int fd;
	char *line;

	fd = open ("foo.txt", O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	free (line);
	close(fd);
	return (0);
}
