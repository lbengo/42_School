/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/21 22:30:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// substr y strjoin

char *get_next_line(int fd)
{
	int		i;
	char	*line;
	static char	*previous_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	line = NULL;
	if (previous_line && strlen_break(previous_line) >= 0)
		return(cut_start_line(previous_line));
	while (strlen_break(line) == -1)
	{
		if (line)
		{
			previous_line = save_previous_line (previous_line, line);
			free(line);
		}
		line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
			return (0);
		line[BUFFER_SIZE] = '\0';
	}
	if (previous_line)
	{
		line = save_previous_line(previous_line, line);
		free (previous_line);
	}
	return (cut_final_line(line, previous_line));
}

char *cut_start_line(char *line)
{
	char	*send_line;
	char	*temp_line;

	send_line = ft_substr(line, 0, strlen_break(line));
	temp_line = ft_strdup(line);
	free (line);
	line = ft_substr(temp_line, strlen_break(temp_line), ft_strlen(temp_line));
	free(temp_line);
	return (send_line);
}

char *cut_final_line(char *line, char *previous_line)
{
	char	*send_line;
	char	*temp_line;

	send_line = ft_substr(line, 0, strlen_break(line));
	free (line);
	previous_line = ft_substr(temp_line, strlen_break(temp_line), ft_strlen(temp_line));
	return (send_line);
}
