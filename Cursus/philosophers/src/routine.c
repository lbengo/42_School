/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:20:44 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/14 19:17:21 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void eating(t_philo *lst)
{
	long int	final_time;
	
	pthread_mutex_lock(lst->fork_r);
		final_time = ft_time() - lst->rules.start_time;
		printf("%ld Philo %d has taken a fork\n", final_time, lst->nbr);
	pthread_mutex_lock(lst->fork_l);
		final_time = ft_time() - lst->rules.start_time;
		printf("%ld Philo %d has taken a fork\n",final_time, lst->nbr);
	final_time = ft_time() - lst->rules.start_time;
	printf("%ld Philo %d is eating\n", final_time, lst->nbr);
	while (final_time != lst->rules.time_to_eat)
		final_time = ft_time() - lst->rules.start_time;
	printf("	Philo %d terminao a = %ld\n", lst->nbr, final_time);
	pthread_mutex_unlock(lst->fork_r);
	pthread_mutex_unlock(lst->fork_l);
}

// par
void	routine_even(t_philo *lst)
{
	int i;

	i = 0;
	while(i < 1)
	{
		eating(lst);
		usleep((lst->rules.time_to_eat / 2) * 1000);
		i++;
	}
	printf("\nterminao\n");
}

// impar
void	routine_odd(t_philo *lst)
{
	long int	final_time;

	usleep((lst->rules.time_to_eat / 2) * 1000);
	final_time = ft_time() - lst->rules.start_time;
	printf("aaaaterminao de esperar =  %ld Philo %d\n", final_time, lst->nbr);
	int i;

	i = 0;
	while(i < 1)
	{
		eating(lst);
		usleep((lst->rules.time_to_eat / 2) * 1000);
		i++;
	}
	
}


void	*routine(void *lst_philos)
{
	t_philo	*lst;

	lst = (t_philo *)lst_philos;
	if (lst->nbr % 2 == 0)
		routine_even(lst);
	else 
		routine_odd(lst);
	return (NULL);
}