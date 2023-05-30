/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:22:06 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/30 09:33:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_find_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i]);
		i++;
	}
	return (path);
}

static char	*delete_start(char *str, int n)
{
	char	*new;
	int		a;

	a = 0;
	new = malloc(sizeof(char) * (strlen(str) - n + 1));
	while (str[n] != '\0')
	{
		new[a] = str[n];
		a++;
		n++;
	}
	new[a] = '\0';
	return (new);
}

static char	**ft_separate_path(char **env)
{
	char	*all_path;
	char	*temp;
	char	**path;
	int		i;

	all_path = ft_find_path(env);
	all_path = delete_start(all_path, 5);
	path = ft_split(all_path, ':');
	free(all_path);
	i = 0;
	while (path[i])
	{
		temp = ft_strdup(path[i]);
		free(path[i]);
		path[i] = NULL;
		path[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	return (path);
}

void	exec_cmd(char *argv, char **env)
{
	int		i;
	char	*command;
	char	**path;
	char	**args;

	path = ft_separate_path(env);
	i = 0;
	while (path[i])
	{
		command = ft_strjoin(path[i], argv);
		args = ft_split(command, ' ');
		execve(args[0], args, env);
		free(command);
		ft_str_free(args);
		i++;
	}
	ft_str_free(path);
	error_message("Error: Command or path not found\n");
}
