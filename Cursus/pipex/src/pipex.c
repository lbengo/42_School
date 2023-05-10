/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/10 17:16:58 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(char *argv)
{
	int val;
	char *command;
	char **args;

	command = ft_strjoin("/bin/", argv);
	args = ft_split(command, ' ');
	val = execve(args[0], args, NULL);
	if (val == -1)
		perror("Error");
	free (command);
}

int error_message(char *msg)
{
	printf("%s", msg);
	return (1);
}

int	check_error(char *argv[])
{
	if (access(argv[1], R_OK) != 0)
		return (error_message("Error\nNo existe el archivo\n"));
	return(0);
}

int	main(int argc, char *argv[])
{
	if (argc == 5)
	{
		if (check_error(argv) == 1)
			return (1);
		ft_pipex(argv[2]);
	}
	else
		printf("Error\nArgumentos esperados: 4. Entregados: %d.\n", (argc - 1));
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
