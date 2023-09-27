/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:59:54 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/09/26 18:24:03 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_thread(t_data *data, t_rules *rules) // creación del hilo
{
	int	i;

	data->th = malloc(sizeof(pthread_t) * ((rules->nbr_philos)));
	if (!data->th)
	{
		free(data->lst_philos);
		free(rules->fork);
		free(rules);
		return (1);
	}
	i = 0;
	while (i < (rules->nbr_philos))
	{
		if (pthread_create(&(data->th[i]), NULL, split_routine, &(data->lst_philos[i])))
			return (1);
		i++;
	}
	return (0);
}

int join_thread(t_data *data, t_rules *rules) // espera la ejecución del hilo
{
	int	i;

	i = 0;
	while (i < (rules->nbr_philos))
	{
		if (pthread_join(data->th[i], NULL))
			return (1);
		i++;
	}
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
			free(*rules);
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
