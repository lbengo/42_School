/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:59:54 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/10/10 18:48:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_data *data, t_rules *rules)
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
		if (pthread_create(&(data->th[i]), NULL, split_routine,
				&(data->lst_philos[i])))
			return (1);
		i++;
	}
	return (0);
}

int	join_thread(t_data *data, t_rules *rules)
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

int	init_fork(t_rules **rules, int nbr)
{
	int	i;

	(*rules)->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr);
	if (!(*rules)->fork)
		return (1);
	i = 0;
	while (i < nbr)
	{
		if (pthread_mutex_init(&((*rules)->fork[i]), NULL) != 0)
		{
			free((*rules)->fork);
			free(*rules);
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&((*rules)->check_and_print), NULL) != 0)
	{
		free((*rules)->fork);
		free(*rules);
		return (1);
	}
	return (0);
}

int	delete_fork(t_rules **rules, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_mutex_destroy(&(*rules)->fork[i]) != 0)
		{
			free((*rules)->fork);
			return (1);
		}
		i++;
	}
	free((*rules)->fork);
	if (pthread_mutex_destroy(&(*rules)->check_and_print) != 0)
	{
		free((*rules)->fork);
		return (1);
	}
	return (0);
}
