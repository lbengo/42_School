/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:20:44 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/19 23:42:03 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	if (philo->rules->philo_dead == 1)
		return (1);
		
	//printf("Philo %d\nt_last_eat = %ld\nt_current = %ld\ncheck_dead = %ld\n\n", philo->nbr-1, philo->t_last_eat, ft_time() - philo->rules->t_start, ft_time() - philo->rules->t_start - philo->t_last_eat);

	if (philo->rules->t_die < ft_time() - philo->rules->t_start - philo->t_last_eat)
	{
		philo->rules->philo_dead = 1;
		printf("po ha muerto el philo %d\n", philo->nbr-1);
		return (1);
	}
	return (0);
}

long int eating(t_philo *philo, t_rules *rules)
{
	long int	time;
	long int	time_start;
	int			nbr;

	nbr = philo->nbr - 1;
			
	pthread_mutex_lock(&(rules->fork[nbr]));
		if (check_dead(philo))
		{
			pthread_mutex_unlock(&(rules->fork[nbr]));
			return (0);
		}
		time_start = ft_time() - rules->t_start;
		printf("%ld Philo %d has taken a fork\n", time_start, nbr + 1);
	
	pthread_mutex_lock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		if (check_dead(philo))
		{
			pthread_mutex_unlock(&(rules->fork[nbr]));
			pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
			return (0);
		}
		time_start = ft_time() - rules->t_start;
		printf("%ld Philo %d has taken a fork\n",time_start, nbr + 1);
	
	if (check_dead(philo))
	{
		pthread_mutex_unlock(&(rules->fork[nbr]));
		pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		return (0);
	}
	time_start = ft_time() - rules->t_start;
	printf("%ld Philo %d is eating\n", time_start, nbr + 1);
	
	time = time_start;
	while (time != rules->t_eat + time_start)
		time = ft_time() - rules->t_start;	
	pthread_mutex_unlock(&(rules->fork[nbr]));
	pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
	return (time);
}

// par
int	routine_even(t_philo *philo)
{
	while(1)
	{
		if (philo->rules->nbr_must_eat && philo->round == philo->rules->nbr_must_eat)
		{
			printf("round = %d", philo->round);
			return (0);
		}
		philo->t_last_eat = eating(philo, philo->rules);
			
		if (check_dead(philo))
			break ;	
		printf("%ld Philo %d is sleeping\n", ft_time() - philo->rules->t_start, philo->nbr);
		usleep((philo->rules->t_sleep) * 1000);
		
		if (check_dead(philo))
			break ;
		printf("%ld Philo %d is thinking\n", ft_time() - philo->rules->t_start, philo->nbr);
	}
	return (0);
}

// impar
int	routine_odd(t_philo *philo)
{
	usleep((philo->rules->t_eat / 2) * 1000);
	while(1)
	{	if (philo->rules->nbr_must_eat && philo->round == philo->rules->nbr_must_eat) //rondas
		{
			printf("round = %d", philo->round);
			return (0);
		}
		
		philo->t_last_eat = eating(philo, philo->rules);
		
		if (check_dead(philo))
			break ;
		printf("%ld Philo %d is sleeping\n", ft_time() - philo->rules->t_start, philo->nbr);
		usleep((philo->rules->t_sleep) * 1000);
		
		if (check_dead(philo))
			break ;
		printf("%ld Philo %d is thinking\n", ft_time() - philo->rules->t_start, philo->nbr);
	}
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