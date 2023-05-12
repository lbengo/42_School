/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/12 13:07:41 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_find_path(char **env)
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

char	**ft_separate_path(char **env)
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
		path[i] = ft_strjoin(temp, "/");
		i++;
	}
	return(path);
}

#define READ_FD 0
#define WRITE_FD 1

int	ft_make_command(char *argv, char **env)
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
		i++;
	}
	if (val == -1)
	{
		printf("aaaaa\n");
		free(command);
		ft_free(args);
		perror("Error");
		exit (0);
	}
	return (0);
}

int	ft_pipex(int argc, char *argv[], char **env) // TODO: habría que hacer un bucle para que vaya pasando comandos x veces
{
	pid_t	pid;
	int		fd1[2];
	//int		fd2[2];

	argc = 0;

	pipe(fd1);
	pid = fork();
	if (pid == -1) // error
		return (1);
	if (pid == 0) // hijo
	{
		close(fd1[READ_FD]);

		dup2(fd1[WRITE_FD], STDOUT_FILENO);
		close(fd1[WRITE_FD]);

		ft_make_command(argv[2], env);
	}
	else // padre
		close(fd1[WRITE_FD]);
	pid = fork();
	if (!pid)
	{
		dup2(fd1[READ_FD], STDIN_FILENO);
		close(fd1[READ_FD]);

		ft_make_command(argv[3], env);
	}
	else
		close(fd1[0]);
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
		printf("Error\nArgumentos esperados: 4. Entregados: %d.\n", (argc - 1));
	return (0);
}
