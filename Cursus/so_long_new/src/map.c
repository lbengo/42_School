/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:15:04 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/14 12:59:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_line(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	ft_map_lines(char *argv)
{
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open (argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	len = strlen_line(line);
	while (line != NULL)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	free (line);
	close(fd);
	return (i);
}

char	**ft_matrix(int len, char *argv)
{
	char	**map;
	int		fd;
	int		i;

	fd = open (argv, O_RDONLY);
	map = malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = get_next_line(fd);
		map[i][strlen_line(map[i])] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
