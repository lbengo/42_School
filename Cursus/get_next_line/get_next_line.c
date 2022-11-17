/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/17 19:22:27 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// substr y strjoin

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
	new_line = NULL;
	while (find_break(line) == 0)
	{
		printf("-VUELTA\n");
		if (line)
		{
			previous_line = line;
			printf("previous_line = %s\n", previous_line);
		}
		line = malloc(sizeof(char) * ((BUFFER_SIZE * i) + 1));
		read(fd, line, BUFFER_SIZE);
		a = 0;
		if (previous_line)
		{
			if(new_line)
				free (new_line);
			printf("ft_strlen de previous = %i \n", ft_strlen(previous_line));
			new_line = malloc(sizeof(char) * ((BUFFER_SIZE * i) + 1));
			while (a < (ft_strlen(previous_line)))
			{
				printf("a\n");
				new_line[a] = previous_line[a];
				a++;
			}
			printf("new_line = %s\n", new_line);
			printf("strlen de new_line = %i\n", ft_strlen(new_line));
			free (previous_line);
			j = 0;
			while(a < (BUFFER_SIZE * i) - 1)
			{
				printf("siiii\n");
				new_line[a] = line[j];
				a++;
			}
			printf("new_line = %s\n", new_line);
		}
		printf("llegas \n");
		line[(BUFFER_SIZE * i)] = '\0';
		printf("-FIN\n");
		i++;
	}

	if (!previous_line)
	{
		printf("line = %s", line);
		return(line);
	}
	printf("a ver hijo ya");
	printf("new_line = %s", new_line);
	return (new_line);
}
