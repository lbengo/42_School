/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:42:09 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/06 12:32:53 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// lista con: number_of_philosophers, time_to_die , time_to_eat , time_to_sleep , number_of_times_each_philosopher_must_eat

int philo(int argc, char *argv)
{
	
}

int	main(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		if (check_error(++argv) == 1)
			return (1);
		if (philo(--argc, argv) == 1)
			return (1);
	}
	else
	{
		printf("Error: Expected 4 or 5 arguments\n");
		return (1);
	}
	return(0);
}
