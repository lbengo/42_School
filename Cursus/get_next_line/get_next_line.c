/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/17 21:17:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// substr y strjoin

char *get_next_line(int fd)
{
	int	i;
	unsigned int	a;
	unsigned int	j;
	char			*line;
	char			*new_line;
	char			*previous_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	
	while(i >= 0)
	{
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // control de malloc
		i = read(fd, line, BUFFER_SIZE);
		printf("line = %s\n", line);
		if (i == -1)
			return (NULL);
		if (i == 0)
			break ;
		if (find_break(line) == 1)
		{
				// guardar el nuevo
			break ;
		}
		// temporal static con malloc

	}

	return (0);
}

	/* while (find_break(line) == 0)
	{
		if (line)
			previous_line = line;
		if (previous_line)
			new_line = ft_strjoin(previous_line, line);
		i++;
		printf("line = %s\n", line);
		printf("new_line = %s\n", new_line);
	}
	if (!previous_line)
		return (line);
	free(previous_line);
	return (new_line); */
