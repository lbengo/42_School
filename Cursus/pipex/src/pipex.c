/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/25 08:41:27 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_FD 0
#define WRITE_FD 1

void	file_in(char *argv[])
{
	int	fd;

	fd = open (argv[0], O_RDONLY);
	if (fd < 0)
		error_message("Error: Function 'open' failed\n");
	if (dup2(fd, STDIN_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(fd);
}

void	make_cmds(char *argv[], int cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1) // error
		error_message("Error: Function 'pid' failed\n");
	if (pid == 0) // hijo
	{
		close(fd[READ_FD]);

		if (dup2(fd[WRITE_FD], STDOUT_FILENO) == -1)
			error_message("Error: Function 'dup2' failed\n");
		close(fd[WRITE_FD]);

		exec_cmd(argv[cmd], env);
	}
	else // padre
	{
		wait(NULL);

		close(fd[WRITE_FD]);

		if (dup2(fd[READ_FD], STDIN_FILENO) == -1)
			error_message("Error: Function 'dup2' failed\n");
		close(fd[READ_FD]);
	}
}

void	file_out(char *argv[], int cmd, char **env)
{
	int		file;

	file = open(argv[cmd+1], O_CREAT | O_TRUNC | O_RDWR , 0644);
	if (file < 0)
		error_message("Error: Function 'open' failed\n");
	if (dup2(file, STDOUT_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(file);

	exec_cmd(argv[cmd], env);
}

void	ft_pipex(char *argv[], int argc, char **env)
{
	int	cmd;

	file_in(argv);
	cmd = 1;
	while (cmd <= argc - 3)
	{
		make_cmds(argv, cmd, env);
		cmd++;
	}
	file_out(argv, cmd, env);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc == 5)
	{
		check_file(argv);
		ft_pipex(++argv, --argc, env);
	}
	else
		error_message("Error: Expected arguments 4\n");
	return (0);
}
