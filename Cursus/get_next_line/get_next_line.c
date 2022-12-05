/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/05 12:06:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			i;
	char		*read_line;
	char		*line;
	char		*temp;
	static char	*previous_line;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd errores lectura del txt
		return (NULL);
	if (previous_line && strlen_break(previous_line) >= 0) // mira si la anterior linea guardada tiene \n
		return (cut_start_line(&previous_line));
	read_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!read_line)
		return (NULL);
	temp = NULL;
	line = NULL;
	i = 1;
	if (previous_line)
	{
		line = ft_strjoin(previous_line, line);
		free (previous_line);
		previous_line = NULL;
	}
	while (strlen_break(line) < 0 && i > 0)
	{
		i = read(fd, read_line, BUFFER_SIZE);
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
		read_line[i] = '\0';
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
	if (strlen_break(line) >= 0) //si hay salto de linea quita el resto y envia la lina sin \n
	{
		if ((strlen_break(line) + 1) < (int)ft_strlen(line))
			previous_line = ft_substr(line, strlen_break(line) + 1, ft_strlen(line));
		temp = ft_strdup(line);
		free(line);
		line = ft_substr(temp, 0, strlen_break(temp) + 1);
		free(temp);
	}
	if (line == NULL)
		free (previous_line);
	return(line);
}

char *cut_start_line(char **previous_line)
{
	char	*line;
	char	*temp;

	line = ft_substr(*previous_line, 0, strlen_break(*previous_line) + 1);
	temp = ft_strdup(*previous_line);
	free (*previous_line);
	*previous_line = NULL;
	*previous_line = ft_substr(temp, strlen_break(temp) + 1, ft_strlen(temp));
	free(temp);
	return (line);
}
