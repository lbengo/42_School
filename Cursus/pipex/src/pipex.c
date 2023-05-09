/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:00:37 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//#include <stdlib.h>

/* void	ft_pipex(argc, argv)
{

} */

void	check_archive (char *argv)
{
	int fd;

	fd = open (argv, O_RDONLY);
	if(fd < 0)
		printf("Error\nNo existe el archivo: %s \n", argv);
	else
		printf("siiii\n");
	close (fd);
}

void	check_error(char *argv[])
{
	check_archive (argv[1]);
}

int	main(int argc, char *argv[])
{
	if (argc == 5)
	{
		check_error(argv);
	}
	else
		printf("Error\nArgumentos esperados: 4. Entregados: %d.\n", (argc - 1));
	//ft_pipex(argc, argv);
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
