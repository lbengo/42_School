/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:11 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/16 09:34:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	break_status(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*end_line(char *s, size_t len)
{
	unsigned int	i;
	char			*line;

	i = 0;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (0);
	while ((len > i))
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*send_line(char *buffer)
{
	size_t	i;
	char *line;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			line = end_line(buffer, i);
			//me guardas en un malloc (line) el buffer resultante
			free (buffer);
			//me liberas el buffer anterior
			return (line);
			//envía el line resultante
		}
		i++;
	}
	return (line);
}
