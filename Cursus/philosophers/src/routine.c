/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:20:44 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/18 18:58:03 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *philo, t_rules *rules)
{
	long int	final_time;
	int			nbr;

	nbr = philo->nbr - 1;

	pthread_mutex_lock(&(rules->fork[nbr]));
		//final_time = ft_time() - lst->rules.start_time;
		//printf("%ld Philo %d has taken a fork\n", final_time, lst->nbr);
	pthread_mutex_lock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		//final_time = ft_time() - lst->rules.start_time;
		//printf("%ld Philo %d has taken a fork\n",final_time, lst->nbr);
		
	final_time = ft_time() - rules->start_time;
	printf("%ld Philo %d is eating\n", final_time, nbr);
	
	while (final_time != rules->time_to_eat)
		final_time = ft_time() - rules->start_time;
	printf("	Philo %d terminao a = %ld\n", nbr, final_time);
	
	pthread_mutex_unlock(&(rules->fork[nbr]));
	pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
}

// par
void	routine_even(t_philo *philo)
{
	int i;

	i = 0;
	while(i < 2)
	{
		eating(philo, philo->rules);
		usleep((philo->rules->time_to_eat / 2) * 1000);
		i++;
	}
	printf("\nterminao\n");
}

// impar
void	routine_odd(t_philo *philo)
{
	long int	final_time;

	usleep((philo->rules->time_to_eat / 2) * 1000);
	final_time = ft_time() - philo->rules->start_time;
	printf("aaaaterminao de esperar =  %ld Philo %d\n", final_time, philo->nbr -1);
	int i;

	i = 0;
	while(i < 2)
	{
		eating(philo, philo->rules);
		usleep((philo->rules->time_to_eat / 2) * 1000);
		i++;
	}
}

void	*routine(void *current_philo)
{
	t_philo	*philo;
		
	philo = (t_philo *)current_philo;
	
	if (philo->nbr % 2 == 0)
		routine_even(philo);
	else 
		routine_odd(philo);
	return (NULL);
}