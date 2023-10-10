/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:20:44 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/10/10 18:53:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo, t_rules *rules)
{
	int	nbr;

	nbr = philo->nbr - 1;
	if (check_and_print(philo, rules, "is eating") == 1)
		return (1);
	ft_usleep(philo, philo->rules->t_eat);
	pthread_mutex_unlock(&(rules->fork[nbr]));
	pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
	if (check_and_print(philo, philo->rules, NULL))
		return (1);
	philo->t_last_eat = ft_time();
	return (0);
}

int	setting_the_table(t_philo *philo, t_rules *rules)
{
	int	nbr;

	nbr = philo->nbr - 1;
	pthread_mutex_lock(&(rules->fork[nbr]));
	if (check_and_print(philo, rules, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&(rules->fork[nbr]));
		return (1);
	}
	pthread_mutex_lock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
	if (check_and_print(philo, rules, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(&(rules->fork[nbr]));
		pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		return (1);
	}
	if (eating(philo, rules) == 1)
	{
		pthread_mutex_unlock(&(rules->fork[nbr]));
		pthread_mutex_unlock(&(rules->fork[(nbr + 1) % (rules->nbr_philos)]));
		return (1);
	}
	return (0);
}

int	routine(t_philo *philo)
{
	while (1)
	{
		if (philo->rules->nbr_must_eat
			&& philo->round == philo->rules->nbr_must_eat)
		{
			philo->rules->philo_dead = 1;
			return (0);
		}
		if (setting_the_table(philo, philo->rules) == 1)
			return (0);
		if (check_and_print(philo, philo->rules, "is sleeping") == 1)
			return (0);
		ft_usleep(philo, (philo->rules->t_sleep));
		if (check_and_print(philo, philo->rules, "is thinking") == 1)
			return (0);
		philo->round ++;
	}
	return (0);
}

void	*split_routine(void *current_philo)
{
	t_philo	*philo;

	philo = (t_philo *)current_philo;
	if (philo->rules->nbr_philos == 1)
		return (one_philo(philo));
	if (philo->nbr % 2 == 0)
		routine(philo);
	else
	{
		ft_usleep(philo, (philo->rules->t_eat / 2));
		routine(philo);
	}
	return (NULL);
}
