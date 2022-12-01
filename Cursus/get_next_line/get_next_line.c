/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/01 11:31:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*read_line;
	char		*line;
	char		*temp;
	//char		*previous_line;
	static int	i = BUFFER_SIZE; // las variables estáticas si se pueden dar valor aquí

	if (fd < 0 || BUFFER_SIZE <= 0) //fd errores lectura del txt
		return (NULL);
	read_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!read_line)
		return (NULL);
	temp = NULL;
	if (i == 0) // ha llegado al final de la lectura
	{
		free(read_line);
		return (0);
	}
	while (i > 0)
	{
		i = read(fd, read_line, BUFFER_SIZE);
		read_line[i] = '\0';
		if (i == -1) // error de lectura
		{
			free (read_line);
			return(0);
		}
		if (line)
		{
			temp = ft_strdup(line);
			free(line);
			line = NULL;
		}
		line = ft_strjoin(temp, read_line);
		free(temp);
	}
	free(read_line);
	return(line);
}
