/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:42:09 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/08 15:46:14 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// lista con: number_of_philosophers, time_to_die , time_to_eat , time_to_sleep , number_of_times_each_philosopher_must_eat

t_rules add_rules(char *argv[])
{
	t_rules rules;

	rules.nbr_philos = ft_atoi(argv[0]);
	rules.time_to_die = ft_atoi(argv[1]);
	rules.time_to_eat = ft_atoi(argv[2]);
	rules.time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		rules.nbr_mut_eat = ft_atoi(argv[4]);
	return(rules);
}

t_philo create_philo(int nbr)
{
	t_philo philo;
	
	philo.nbr = nbr;
	return (philo);
}

t_philo	*add_philos(int nbr)
{
	t_philo	*lst_philos;
	int		i;

	lst_philos = malloc(sizeof(t_philo) * nbr);
	if (!lst_philos)
		return (NULL);
	i = 0;
	while (i < nbr)
	{
		lst_philos[i] = create_philo(i + 1);
		i++;
	}
	return (lst_philos);
}

int philo(char *argv[])
{
	t_rules	rules;
	t_philo	*lst_philos;
	
	rules = add_rules(argv);
	lst_philos = add_philos(rules.nbr_philos);
	
	//
	int i = 0;
	while (i < rules.nbr_philos)
	{
		printf("philo[%d] = %d\n", i + 1, (lst_philos[i]).nbr);
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
