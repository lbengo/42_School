/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:22:06 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/23 17:38:35 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	select_file_in(char *argv[])
{
	if (ft_strncmp(argv[0], "here_doc", 7) == 0)
		here_doc(argv);
	else
		file_in(argv);
}

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

void	exec_cmd(char *argv, char **env) // Ejecuta el comando
{
	int i;
	char *command;
	char **path;
	char **args;

	path = ft_separate_path(env);
	i = 0;
	while(path[i])
	{
		command = ft_strjoin(path[i], argv);
		args = ft_split(command, ' ');
		execve(args[0], args, NULL);
		free(command);
		ft_str_free(args);
		i++;
	}
	ft_str_free(path);
	error_message("Error: Command or path not found\n");
	exit(1);
}
