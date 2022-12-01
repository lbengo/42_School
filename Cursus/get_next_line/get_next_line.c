/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/01 18:15:15 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			i;
	char		*read_line;
	char		*line;
	char		*temp;
	static char		*previous_line;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd errores lectura del txt
		return (NULL);
	if (previous_line && strlen_break(previous_line) >= 0) // mira si la anterior linea guardada tiene \n
		return (cut_start_line(previous_line));
	read_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!read_line)
		return (NULL);
	temp = NULL;
	line = NULL;
	i = 1;
	while (strlen_break(line) < 0 && i > 0)
	{
		i = read(fd, read_line, BUFFER_SIZE);
		read_line[i] = '\0';
		if (i == 0) // ha llegado al final de la lectura
		{
			free(read_line);
			return (line);
		}
		if (i == -1) // si hay error en la lectura
		{
			free (read_line);
			free(line);
			return (0);
		}
		if (line)
		{
			temp = ft_strdup(line);
			free(line);
		}
		line = ft_strjoin(temp, read_line);
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
	}
	free (read_line);
	return(line);
}

char *cut_start_line(char *previous_line)
{
	char	*line;
	char	*temp;

	line = ft_substr(previous_line, 0, strlen_break(previous_line));
	temp = ft_strdup(previous_line);
	free (previous_line);
	previous_line = NULL;
	previous_line = ft_substr(temp, strlen_break(temp) + 1, ft_strlen(temp));
	free(temp);
	return (line);
}
