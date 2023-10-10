/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:00:11 by lbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 20:02:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	if (philo->rules->philo_dead == 1)
		return (1);
	if (philo->rules->t_die < (ft_time() - philo->t_last_eat))
	{
		philo->rules->philo_dead = 1;
		printf("%ld %d died\n", ft_time() - philo->rules->t_start, philo->nbr);
		return (1);
	}
	return (0);
}

int	ft_usleep(t_philo *philo, long int time)
{
	long int	time_start;

	time_start = ft_time();
	while (check_dead(philo) == 0)
	{
		if (ft_time() - time_start > time)
			return (0);
		usleep(500);
	}
	return (0);
}

int	check_and_print(t_philo *philo, t_rules *rules, char *str)
{
	if (check_dead(philo))
		return (1);
	printf("%ld %d %s\n", ft_time() - rules->t_start, philo->nbr, str);
	return (0);
}

void	*one_philo(t_philo *philo)
{
	long int	time;

	time = ft_time() - philo->rules->t_start;
	printf("%ld %d has taken a fork\n", time, philo->nbr);
	printf("%ld %d died\n", time + philo->rules->t_eat, philo->nbr);
	return (NULL);
}
