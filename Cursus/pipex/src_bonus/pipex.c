/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/27 19:26:02 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	ft_pipex(char *argv[], int argc, char **env)
{
	int	cmd;

	cmd = select_file_in(argv);
	printf("argv[%i]= %s\n", cmd, argv[cmd]);
	while (cmd <= argc - 3)
	{
		make_cmds(argv, cmd, env);
		cmd++;
	}
	printf("cmd = %s\n", argv[cmd]);
	printf("cmd = %s\n", argv[cmd+1]);
	select_file_out(argv, cmd, env);
}

int	main(int argc, char *argv[], char **env)
{
	if (argc >= 5)
	{
		check_file(argv);
		ft_pipex(++argv, --argc, env);
	}
	else
		error_message("Error: Expected arguments 4\n");
	return (0);
}
