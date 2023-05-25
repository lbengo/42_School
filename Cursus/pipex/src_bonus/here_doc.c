/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:18 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/25 15:43:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//file = open(".new_file.txt", O_CREAT | O_APPEND | O_RDWR , 0644);

#include "pipex_bonus.h"

char	*get_line(int fd)
{
	char	*line;
	char	*read_c;
	char	*temp;

	read_c = malloc(sizeof(char) * 2);
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
		printf("(holii = %s)", read_c);
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
	int		file;
	char *line;

	file = open(".new_file.txt", O_CREAT | O_TRUNC | O_RDWR , 0644);
	if (file < 0)
		error_message("Error: Function 'open' failed\n");
	while (1)
	{
		line = get_line(0);
		printf("aaaaa\n");
		if (ft_strncmp(line, argv[1], strlen(argv[1])) == 0)
			break;
		write(file, line, ft_strlen(line));
		free(line);
	}
	printf("eeeee\n");
	if (dup2(file, STDIN_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(file);
	//if (unlink(".new_file") < 0)
	//	error_message("Error: Function 'unlink' failed\n");
}

