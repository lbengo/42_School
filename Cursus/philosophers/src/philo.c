/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:42:09 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/12 14:58:23 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// lista con: number_of_philosophers, time_to_die , time_to_eat , time_to_sleep , number_of_times_each_philosopher_must_eat

int philo(char *argv[])
{
	t_rules	rules;
	t_data	data;
	
	rules = add_rules(argv);
	if (init_fork(&data.fork, rules.nbr_philos))
		return (1);
	if (add_philos(rules.nbr_philos, &data))
		return (1);
	if (create_thread(rules, &data))
		return (1);
	if (delete_thread(rules, &data))
		return (1);
	if (delete_fork(&data.fork, rules.nbr_philos))
		return (1);
	
	//
	int i = 0;
	while (i < rules.nbr_philos)
	{
		printf("philo[%d] = %d\n", i + 1, (data.lst_philos[i]).nbr);
		i++;
	}
	//
	
	/* printf("rules.nbr_philo = %d\n", rules.nbr_philos);
	printf("rules.time_to_die = %d\n", rules.time_to_die);
	printf("rules.time_to_eat = %d\n", rules.time_to_eat);
	printf("rules.time_to_sleep = %d\n", rules.time_to_sleep);
	if (argc == 5)
		printf("rules.nbr_mut_eat = %d\n", rules.nbr_mut_eat); */
	return(0);
}

int	main(int argc, char *argv[])
{
	if (check_error (--argc, ++argv))
		return(1);
	if (philo(argv))
			return (1);
	return(0);
}
