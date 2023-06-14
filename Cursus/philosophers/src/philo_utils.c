/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:28:02 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/14 12:35:49 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + str[i] - '0';
		i++;
	}
	return (count);
}

t_rules	add_rules(char *argv[])
{
	t_rules	rules;
	
	rules.start_time = ft_time();
	rules.nbr_philos = ft_atoi(argv[0]);
	rules.time_to_die = ft_atoi(argv[1]);
	rules.time_to_eat = ft_atoi(argv[2]);
	rules.time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		rules.nbr_mut_eat = ft_atoi(argv[4]);
	return (rules);
}

t_philo	create_philo(int n_philos, int n_philo, pthread_mutex_t *fork, t_rules rules)
{
	t_philo	philo;

	philo.rules = rules;
	philo.nbr = n_philo + 1;
	philo.fork_r = &fork[n_philo];
	philo.fork_l = &fork[(n_philo + 1) % n_philos];
	return (philo);
}

int	add_philos(int n_philos, t_data *data, t_rules rules)
{
	int	n_philo;

	data->lst_philos = malloc(sizeof(t_philo) * n_philos);
	if (!data->lst_philos)
		return (1);
	n_philo = 0;
	while (n_philo < n_philos)
	{
		data->lst_philos[n_philo] = create_philo(n_philos, n_philo, data->fork, rules);
		n_philo++;
	}
	return (0);
}