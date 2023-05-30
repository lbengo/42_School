/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:51:06 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/30 09:26:16 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	file_append_out(char *argv[], int cmd, char **env)
{
	int	file;

	file = open(argv[cmd + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
	if (file < 0)
		error_message("Error: Function 'open' failed\n");
	if (dup2(file, STDOUT_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(file);
	exec_cmd(argv[cmd], env);
}

static void	file_trunc_out(char *argv[], int cmd, char **env)
{
	int	file;

	file = open(argv[cmd + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file < 0)
		error_message("Error: Function 'open' failed\n");
	if (dup2(file, STDOUT_FILENO) == -1)
		error_message("Error: Function 'dup2' failed\n");
	close(file);
	exec_cmd(argv[cmd], env);
}

void	select_file_out(char *argv[], int cmd, char **env)
{
	if (ft_cmpsame("here_doc", argv[0]) == 0)
		file_append_out(argv, cmd, env);
	file_trunc_out(argv, cmd, env);
}
