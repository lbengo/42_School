/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/17 20:28:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// substr y strjoin

char *get_next_line(int fd)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	j;
	char			*line;
	char			*new_line;
	char			*previous_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	previous_line = NULL;
	line = NULL;
	while (find_break(line) == 0)
	{
		if (line)
			previous_line = line;
		line = malloc(sizeof(char) * ((BUFFER_SIZE * i) + 1));
		read(fd, line, BUFFER_SIZE);
		printf("hola\n");
		if (previous_line)
		{
			new_line = ft_strjoin(previous_line, line);
			free(previous_line);
		}
		i++;
	}
	if (!previous_line)
		return(line);
	return (new_line);
}
