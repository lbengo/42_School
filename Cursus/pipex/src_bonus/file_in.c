/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:53:26 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/27 19:19:49 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_line(int fd)
{
	char	*line;
	char	*read_c;
	char	*temp;

	read_c = ft_calloc(sizeof(char), 2);
	if (!read_c)
		error_message("Error: Function 'read' failed\n");
	line = NULL;
	while (read_c[0] != '\n')
	{
		if (read(fd, read_c, 1) < 0)
		{
			free(read_c);
			error_message("Error: Function 'read_c' failed\n");
		}
		read_c[1] = '\0';
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, read_c);
		free(temp);
	}
	free(read_c);
	return (line);
}

void	here_doc(char *argv[])
{
	int		fd;
	char	*line;

	fd = open(".new_file.txt", O_CREAT | O_TRUNC | O_WRONLY , 0644);
	if (fd < 0)
		error_message("Error: Function 'open' failed\n");
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_line(0);
		if (ft_cmpsame(argv[1], line) == 0)
			break;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	file_in(".new_file.txt");
	close(fd);
	if (unlink(".new_file.txt") < 0)
		error_message("Error: Function 'unlink' failed\n");
}

void	file_in(char *file)
{
	int	fd;

	fd = open (file, O_RDONLY);
	if (fd < 0)
		error_message("Error: Function 'open' failed\n");
	if (dup2(fd, STDIN_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(fd);
}

int	select_file_in(char *argv[])
{
	if (ft_cmpsame("here_doc", argv[0]) == 0)
	{
		here_doc(argv);
		return(2);
	}
	file_in(argv[0]);
	return(1);
}
