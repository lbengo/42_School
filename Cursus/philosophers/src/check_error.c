/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:31:22 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/08 12:57:21 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_nbrs(char *argv[])
{
	int	i;
	int	a;

	i = 0;
	while (argv[i])
	{
		a = 0;
		while (argv[i][a])
		{
			if (argv[i][a] >= '0' && argv[i][a] <= '9')
				a++;
			else
			{
				printf("Error: '%s' Argumento inválido\n", argv[i]);
				return (1);
			}
		}
		if (a == 0)
		{
			printf("Error: Argumento %d no tiene valor\n", i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char *argv[])
{	
	if (argc < 4 || argc > 5)
	{
		printf("Error: Expected 4 or 5 arguments\n");
		return (1);
	}
	if (check_nbrs(argv))
		return (1);
	return (0);
}
