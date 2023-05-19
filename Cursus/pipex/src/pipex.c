/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/19 21:56:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_FD 0
#define WRITE_FD 1

int	ft_enter_file(char *argv[], char **env, int fd[2])
{
	pid_t	pid;

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

		ft_execute_command(argv[1], env);
			return (1);

	}
	else // padre
		close(fd[WRITE_FD]);
	return (0);
}

int	ft_create_file(char *argv[], char **env, int fd[2])
{
	pid_t	pid;
	int		file;

	pid = fork(); // último
	if (pid == -1) // error
		return (1);
	if (pid == 0)
	{
		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);

		file = open(argv[3], O_CREAT | O_TRUNC | O_RDWR , 0644);
		dup2(file, STDOUT_FILENO);
		close(file);
		ft_execute_command(argv[2], env);
		return (1);
	}
	else
		close(fd[WRITE_FD]);
	return (0);
}

int	ft_pipex(char *argv[], char **env)
{
	int	fd[2];

	pipe(fd);
	if (ft_enter_file(argv, env, fd) == 1)
		return (1);
	if (ft_create_file(argv, env, fd) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc == 5)
	{
		if (check_file(argv) == 1)
			return (1);
		if (ft_pipex(++argv, env) == 1)
			return (1);
	}
	else
		error_message("Error: Argumentos esperados: 4\n");
	return (0);
}
