/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/17 16:56:22 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_break(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	j;
	char			*line;
	char			*new_line;
	char			*previous_line;

	if (fd == -1)
		return (NULL);
	i = 1;
	previous_line = NULL;
	line = NULL;
	while (find_break(line) == 0)
	{
		if (line)
		{
			printf("entra en line \n");
			previous_line = line;
			printf("previous_line = %s\n", previous_line);
		}
		line = malloc(sizeof(char) * ((BUFFER_SIZE * i) + 1));
		read(fd, line, BUFFER_SIZE);
		printf("buffer_size = %i\n", (BUFFER_SIZE * i) + 1);
		a = 0;
		if (previous_line)
		{ // substr y strjoin
			printf("entra en previous");
			printf("ft_strlen = %i \n", ft_strlen(previous_line));
			while (a < (ft_strlen(previous_line)))
			{
				printf("a");
				new_line[a] = previous_line[a];
				a++;
			}
			printf("new_line = %s\n", new_line);
			free (previous_line);
			j = 0;
			while(a < ft_strlen(line))
			{
				new_line[a] = line[j];
				a++;
			}
			printf("new_line = %s\n", new_line);
		}
		printf("llegas \n");
		line[(BUFFER_SIZE * i)] = '\0';
		printf("o no \n");
		i++;
	}

	if (!previous_line)
	{
		printf("line = %s", line);
		return(line);
	}
	printf("new_line = %s", new_line);
	return (new_line);
}
