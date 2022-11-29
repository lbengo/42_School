/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/29 22:01:56 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*line;
	static char	*previous_line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd errores lectura del txt
		return (NULL);
	if (previous_line && strlen_break(previous_line) >= 0)
	{
		line = ft_substr(previous_line, 0, strlen_break(previous_line)); // la linea hasta \n que voy a enviar
		temp = ft_strdup(previous_line);
		free (previous_line);
		previous_line = NULL;
		previous_line = ft_substr(temp, strlen_break(temp) + 1, ft_strlen(temp)); // la linea que tengo que guardar
		free(temp);
		return (line);
	}
	line = NULL;
	temp = NULL;
	i = 1;
	while (strlen_break(line) < 0 && i > 0)
	{
		if (line)
		{
			if (previous_line)
			{
				temp = ft_strdup (previous_line);
				free (previous_line);
				previous_line = NULL;
			}
			previous_line = ft_strjoin(temp, line);
			free (line);
			line = NULL;
			if (temp)
			{
				free (temp);
				temp = NULL;
			}
		}
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!line)
			return (NULL);
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1) // error de lectura
		{
			free (line);
			return(0);
		}
		line[i] = '\0';
		if (i == 0) // ha llegado al final de la lectura
			break;
	}
	if (line[0] == 0 && line == NULL)
		return(0);
	temp = ft_strdup(line);
	free (line);
	line = NULL;
	line = ft_strjoin(previous_line, temp); // linea completa con \n
	free (previous_line);
	previous_line = NULL;
	free(temp);
	temp = NULL;
	temp = ft_strdup (line);
	free (line);
	line = NULL;
	line = ft_substr(temp, 0, strlen_break(temp)); // quitar /n a la linea final
	previous_line = ft_substr(temp, strlen_break(temp) + 1, ft_strlen(temp));
	free(temp);
	if (line == NULL)
		free(previous_line);
	return(line);
}
