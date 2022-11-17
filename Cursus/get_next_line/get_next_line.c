/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/17 14:02:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	unsigned int i;
	unsigned int a;
	char	*previous_line;
	//char	*new_line;

	if (fd == -1)
		return (NULL);
	i = 1;
	previous_line = NULL;
	line = NULL;
	while (find_break(line) == 0)
	{
		if (line)
			previous_line = line;
		line = malloc(sizeof(char) * (BUFFER_SIZE * i + 1));
		a = 0;
		if (previous_line)
		{
			while (a < (BUFFER_SIZE * i))
			{
				line[a] = previous_line[a];
				a++;
			}
			free (previous_line);
		}
		read(fd, line, BUFFER_SIZE);
		line[BUFFER_SIZE] = '\0';
		//printf("la line es = %s \n", line);
		i++;
	}
	return (line);
}
