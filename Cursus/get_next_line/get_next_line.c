/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/12/06 19:32:34 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_file(int fd, char **line)
{
	char	*read_line;
	char	*temp;
	int		i;

	read_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_line)
		return (-1);
	i = 1;
	while (strlen_break(*line) < 0 && i > 0)
	{
		i = read(fd, read_line, BUFFER_SIZE);
		if (i <= 0) // ha llegado al final de la lectura o se ha producido un error en la lectura
		{
			free (read_line);
			return (i);
		}
		read_line[i] = '\0';
		temp = ft_strdup(*line);
		free(*line);
		*line = NULL;
		*line = ft_strjoin(temp, read_line);
		free(temp);
	}
	free (read_line);
	return (i);
}

static void	ft_add_line(char **line, char **previous_line)
{
	*line = ft_strjoin(*previous_line, *line);
	free (*previous_line);
	*previous_line = NULL;
	if (*line[0] == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

static char	*cut_line(char **line, char **p_line, int is_new_line)
{
	char	*temp;

	if (is_new_line == 1) // añade y envía line hasta el \n de la linea anterior y recorta para la siguiente linea
	{
		*line = ft_substr(*p_line, 0, strlen_break(*p_line) + 1);
		temp = ft_strdup(*p_line);
		free (*p_line);
		*p_line = ft_substr(temp, strlen_break(temp) + 1, ft_strlen(temp));
		free(temp);
		return (*line);
	}
	else // recortaline es hasta \n y previous_line el resto
	{
		*p_line = ft_substr(*line, strlen_break(*line) + 1, ft_strlen(*line));
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_substr(temp, 0, strlen_break(temp) + 1);
		free(temp);
	}
	return(0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*previous_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd errores lectura del txt
		return (NULL);
	line = NULL;
	if (previous_line && strlen_break(previous_line) >= 0) // mira si la anterior linea guardada tiene \n
		return (cut_line(&line, &previous_line, 1));
	if (previous_line)
		ft_add_line(&line, &previous_line); // añade dentro de line lo que haya en previous_line
	i = ft_read_file(fd, &line); // lee el file y lo añade dentro de line
	if (i == -1)
	{
		free(line);
		return (0);
	}
	else if (i > 0)
	{
		if (strlen_break(line) >= 0) //si hay salto de linea quita el resto y envia la lina sin \n
			cut_line(&line, &previous_line, 0);
		if (line == NULL)
			free (previous_line);
	}
	return (line);
}