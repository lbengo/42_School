/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/04 11:23:07 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

/* int	main(int argc, char *argv[], char **env)
{
	argv = NULL;
	if (argc == 1)
	{
		printf("Error");
		return (0);
	}
	return (0);
} */

int	main(void)
{
	int fd[2];
	pid_t pidC;
	char buf[10];
	int num;

	pipe(fd); /* TODO: error manamgent. */
	pidC = fork();

	if (pidC == 0) /* hijo */
	{
		close(fd[0]);
		write(fd[1], "abdce", 5);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		num = read(fd[0], buf, sizeof(buf));
		printf("Padre lee %d bytes: %s\n", num, buf);
		close(fd[0]);
	}
	return (0);
}
