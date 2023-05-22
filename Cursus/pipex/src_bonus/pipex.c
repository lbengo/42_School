/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/22 15:43:17 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_FD 0
#define WRITE_FD 1

int	file_in(char *argv[])
{
	int	fd[2];

	pipe(fd);
	close(fd[WRITE_FD]);

	fd[READ_FD] = open (argv[0], O_RDONLY);
	dup2(fd[READ_FD], STDIN_FILENO);
	close(fd[READ_FD]);

	return (fd[READ_FD]);
}

int	make_cmds(char *argv[], int cmd, char **env, int fdin)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork(); // último
	if (pid == -1) // error
		return (1);

	if (pid == 0)
	{
		dup2(fdin, fd[READ_FD]);
		close(fdin);

		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);

		dup2(fd[WRITE_FD], STDOUT_FILENO);
		close(fd[WRITE_FD]);

		exec_cmd(argv[cmd], env);
		return (1);
	}
	else // padre
	{
		wait(NULL);
		close(fd[WRITE_FD]);
	}
	return (fd[READ_FD]);
}

int	file_out(char *argv[], int cmd, char **env, int fdin)
{
	int		file;

	dup2(fdin, STDIN_FILENO);
	close(fdin);

	file = open(argv[cmd+1], O_CREAT | O_TRUNC | O_RDWR , 0644);
	dup2(file, STDOUT_FILENO);
	close(file);

	exec_cmd(argv[cmd], env);
	return (1);
}

int	ft_pipex(char *argv[], int argc, char **env)
{
	int	fd;
	int	cmd;

	fd = file_in(argv);
	cmd = 1;
	while (cmd <= argc - 3)
	{
		fd = make_cmds(argv, cmd, env, fd);
		if (fd == 1)
			return (1);
		cmd++;
	}
	fd = file_out(argv, cmd, env, fd);
	if (fd == 1)
			return (1);
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc >= 5)
	{
		if (check_file(argv) == 1)
			return (1);
		if (ft_pipex(++argv, --argc, env) == 1)
			return (1);
	}
	else
		error_message("Error: Minimum expected arguments 4\n");
	return (0);
}
