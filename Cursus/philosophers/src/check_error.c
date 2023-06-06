/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:31:22 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/06 12:31:32 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_error(char *argv[]) // checkeo de número entero
{
	int i;
	int a;

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
				printf("Error: '%s' No es un número entero\n", argv[i]);
				return (1);
			}
		}
		i++;
	}
	return(0);
}