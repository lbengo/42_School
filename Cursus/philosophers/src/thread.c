/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:59:54 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/19 12:33:43 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_thread(t_data *data, t_rules *rules)
{
	int	i;

	data->th = malloc(sizeof(pthread_t) * rules->nbr_philos);
	if (!data->th)
		return (1);
	i = 0;
	while (i < rules->nbr_philos)
	{
		if (pthread_create(&(data->th[i]), NULL, routine, &(data->lst_philos[i])))
			return (1);
		i++;
	}
	return (0);
}

int delete_thread(t_data *data, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philos)
	{
		if (pthread_join(data->th[i], NULL))
			return (1);
		i++;
	}
	free(data->th);
	return (0);
}

int init_fork(t_rules **rules, int nbr)
{
	int i;

	(*rules)->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	if (!(*rules)->fork)
		return (1);
	i = 0;
	while(i < nbr)
	{
		if (pthread_mutex_init(&((*rules)->fork[i]), NULL) != 0) // inicio del mutex
		{
			free((*rules)->fork);
			return (1);
		}
		i++;
	}
	return (0);
}

int delete_fork(t_rules **rules, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_mutex_destroy(&((*rules)->fork[i])) != 0) // finalización del mutex
		{
			free((*rules)->fork);
			return (1);
		}
		i++;
	}
	free((*rules)->fork);
	return (0);
}
