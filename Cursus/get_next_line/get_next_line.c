/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:46:34 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/16 09:44:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	int		end;
	char	*line;

	if (fd == -1)
		return (NULL);
	if (*buffer)
	{
		if (break_status(buffer) == 1)
			line = send_line(buffer);
	}
	if (!buffer || (*buffer && break_status(buffer) == 0))
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == 0)
			return (NULL);
		line = send_line(buffer);
	}
	return (line);
}
