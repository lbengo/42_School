/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:20:44 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/19 19:11:14 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo, long int t_current)
{
	if (philo->rules->philo_dead == 1)
		return (1);
	if (philo->rules->t_die <= ft_time(t_current))
	{
		philo->rules->philo_dead = 1;
		printf("po ha muerto el philo %d\n", philo->nbr-1);
		return (1);
	}
	return (0);
}

void eating(t_philo *philo, t_rules *rules)
{
	long int	time;
	long int	time_start;
	int			nbr;

	nbr = philo->nbr - 1;

	pthread_mutex_lock(&(rules->fork[nbr]));
		//time = ft_time() - lst->rules.t_start;
		//printf("%ld Philo %d has taken a fork\n", time, lst->nbr);
	pthread_mutex_lock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		//time = ft_time() - lst->rules.t_start;
		//printf("%ld Philo %d has taken a fork\n",time, lst->nbr);
		
	time_start = ft_time(rules->t_start);
	printf("%ld Philo %d is eating\n", time_start, nbr);
	
	time = time_start;
	while (time != rules->t_eat + time_start)
		time = ft_time(rules->t_start);	
	pthread_mutex_unlock(&(rules->fork[nbr]));
	pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
}

// par
int	routine_even(t_philo *philo)
{
	int i;

	i = 0;
	while(i < 2)
	{
		eating(philo, philo->rules);
		if (philo->rules->philo_dead == 1)
			return (1);
		printf("%d Philo %d is sleeping\n", ft_time(philo->rules->t_start), philo->nbr);
		usleep((philo->rules->t_eat / 2) * 1000);
		if (check_dead(philo, philo->rules->t_start))
			return (1);
		i++;
	}
	printf("\nterminao rutina = %d\n", philo->nbr - 1);
	return (0);
}

// impar
int	routine_odd(t_philo *philo)
{
	usleep((philo->rules->t_eat) * 1000);
	if (check_dead(philo, philo->rules->t_start))
		return (1);
		
	int i;

	i = 0;
	while(i < 2)
	{
		eating(philo, philo->rules);
		usleep((philo->rules->t_eat / 2) * 1000);
		
		i++;
	}
	printf("terminao rutina = %d\n", philo->nbr -1);
	return (0);
}

void	*routine(void *current_philo)
{
	t_philo		*philo;

	philo = (t_philo *)current_philo;
	if (philo->nbr % 2 == 0)
		routine_even(philo);
	else 
		routine_odd(philo);
	return (NULL);
}