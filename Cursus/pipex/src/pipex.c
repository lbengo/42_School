/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/18 16:20:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **env) // encuentra path dentro de env
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH") != NULL)
			return(ft_strstr(env[i], "PATH"));
		i++;
	}
	return(path);
}

char	**ft_separate_path(char **env) // separa y pone bien cada path
{
	char	*all_path;
	char	*temp;
	char	**path;
	int		i;

	all_path = ft_find_path(env);
	path = ft_split(all_path, ':');
	i = 0;
	while (path[i])
	{
		temp = path[i];
		free(path[i]);
		path[i] = NULL;
		path[i] = ft_strjoin(temp, "/");
		i++;
	}
	return(path);
}

#define READ_FD 0
#define WRITE_FD 1

void	ft_make_command(char *argv, char **env) // Ejecuta el comando
{
	int i;
	int val;
	char *command;
	char **path;
	char **args;

	path = ft_separate_path(env);
	i = 0;
	while(path[i])
	{
		command = ft_strjoin(path[i], argv);
		args = ft_split(command, ' ');
		val = execve(args[0], args, NULL);
		free(command);
		ft_str_free(args);
		i++;
	}
	ft_str_free(path);
	error_message("Error: Command or path not found\n");
}

int	ft_pipex(int argc, char *argv[], char **env) // TODO: habría que hacer un bucle para que vaya pasando comandos x veces
{
	pid_t	pid;
	int		fd[2];
	int		file;

	argc = 0;

	pipe(fd);

	pid = fork(); // primero
	if (pid == -1) // error
		return (1);
	if (pid == 0) // hijo
	{
		fd[READ_FD] = open (argv[1], O_RDONLY);
		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);

		dup2(fd[WRITE_FD], STDOUT_FILENO);
		close(fd[WRITE_FD]);

		ft_make_command(argv[2], env);
	}
	else // padre
		close(fd[WRITE_FD]);

	pid = fork(); // último
	if (pid == -1) // error
		return (1);
	if (pid == 0)
	{
		dup2(fd[READ_FD], STDIN_FILENO);
		close(fd[READ_FD]);

		file = open(argv[4], O_CREAT | O_TRUNC | O_RDWR , 0644);
		dup2(file, STDOUT_FILENO);
		close(file);
		ft_make_command(argv[3], env);
	}
	else
		close(fd[WRITE_FD]);
		
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc == 5)
	{
		if (check_file(argv) == 1)
			return (1);
		if (ft_pipex(argc, argv, env) == 1)
			return (1);
	}
	else
		error_message("Error: Argumentos esperados: 4\n");
	return (0);
}
