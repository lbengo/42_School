/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:42:09 by lbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 16:11:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// lista con: number_of_philosophers, time_to_die , time_to_eat , time_to_sleep , number_of_times_each_philosopher_must_eat
// return(1) debe tener un retorno bn con un printf q diga q pasa

int philo(char *argv[])
{
	t_rules	*rules;
	t_data	data;

	add_rules(&rules, argv);
	if (init_fork(&rules, rules->nbr_philos))
		return (1);
	if (add_philos(&data, &rules))
		return (1);
	if (create_thread(&data, rules))
		return (1);
	if (join_thread(&data, rules))
		return (1);
	if (delete_fork(&rules, rules->nbr_philos))
		return (1);
	printf("ejercicio termiano\n");
	free(data.lst_philos);
	free(rules);
	return(0);
}

int	main(int argc, char *argv[])
{
	if (check_error (--argc, ++argv))
		return(1);
	if (philo(argv))
	{
		printf("algo ha pasao :(\n");
		return (1);
	}
	return(0);
}
