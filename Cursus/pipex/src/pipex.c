/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/12 10:20:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	ft_make_command(char *argv)
{
	int val;
	char *command;
	char **args;


	command = ft_strjoin("/bin/", argv);
	args = ft_split(command, ' ');
	val = execve(args[0], args, NULL);
	if (val == -1)
		perror("Error");
	//printf("aaaaa");
	free (command); // no se libera adecuadamente
	ft_free(args); // no se libera adecuadamente
} */

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

void	ft_make_command(char *argv)
{
	int val;
	char *command;
	char **args;

	command = ft_strjoin("/bin/", argv);
	args = ft_split(command, ' ');
	val = execve(args[0], args, NULL);
	if (val == -1)
		perror("Error");
		
	free (command); // no se libera adecuadamente
	ft_free(args); // no se libera adecuadamente
}

#define READ_FD 0
#define WRITE_FD 1

int	ft_pipex(int argc, char *argv[]) // TODO: habría que hacer un bucle para que vaya pasando comandos x veces
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

		ft_make_command(argv[2]);
	}
	else // padre
	{
		close(fd1[WRITE_FD]);

		dup2(fd1[READ_FD], STDIN_FILENO);
		close(fd1[READ_FD]);

		ft_make_command(argv[3]);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 5)
	{
		if (check_file(argv) == 1)
			return (1);
		if (ft_pipex(argc, argv) == 1)
			return (1);
	}
	else
		printf("Error\nArgumentos esperados: 4. Entregados: %d.\n", (argc - 1));
	//exit(0);
	return (0);
}

/* int	main(int argc, char *argv[])
{
	argv = NULL;
	if (argc < 5)
	{
		printf("Error\nArgumentos mínimos esperados: 4. Entregados: %d.\n", (argc - 1));
		return (1);
	}
	ft_pipex(argc, argv);
	return (0);
} */
