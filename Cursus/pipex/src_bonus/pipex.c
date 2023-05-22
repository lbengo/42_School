/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/22 10:18:59 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_FD 0
#define WRITE_FD 1

int	file_in(char *argv[], char **env)
{
	pid_t	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid == -1) // error
		return (1);
	if (pid == 0) // hijo
	{
		fd[READ_FD] = open (argv[0], O_RDONLY);
		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);

		dup2(fd[WRITE_FD], STDOUT_FILENO);
		close(fd[WRITE_FD]);

		exec_cmd(argv[1], env);
		return (1);
	}
	else // padre
	{
		close(fd[WRITE_FD]);
		wait(NULL);
	}
	return (fd[READ_FD]);
}

int	make_cmds(char *argv[], char **env, int fdin)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork(); // último
	if (pid == -1) // error
		return (1);
	if (pid == 0)
	{
		dup2(fdin, STDIN_FILENO);
		close(fdin);

		dup2(fd[WRITE_FD], STDOUT_FILENO);
		close(fd[WRITE_FD]);

		exec_cmd(argv[2], env);
		return (1);
	}
	else // padre
	{
		wait(NULL);
		close(fd[WRITE_FD]);
	}

	return (fd[READ_FD]);
}

int	file_out(char *argv[], char **env, int fdin)
{
	int		file;

	dup2(fdin, STDIN_FILENO);
	close(fdin);

	file = open(argv[4], O_CREAT | O_TRUNC | O_RDWR , 0644);
	dup2(file, STDOUT_FILENO);
	close(file);

	exec_cmd(argv[3], env);
	return (1);
}

//FILE_IN Y FILE_OUT MAKE_CMDS EXEC_CMD

int	ft_pipex(char *argv[], char **env)
{
	int	fd;

	fd = file_in(argv, env);
	fd = make_cmds(argv, env, fd);
	file_out(argv, env, fd);
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc >= 5)
	{
		if (check_file(argv) == 1)
			return (1);
		if (ft_pipex(++argv, env) == 1)
			return (1);
	}
	else
		error_message("Error: Argumentos mínimos esperados: 4\n");
	return (0);
}
