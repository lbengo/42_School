/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:59:54 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/12 15:03:53 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *lst_philos)
{
	t_philo			*lst;

	lst = (t_philo *)lst_philos;
	lst[0].nbr = lst[0].nbr + 1;
	printf("lst = %d\n", lst[0].nbr);
	return (NULL);
}

int create_thread(t_rules rules, t_data *data)
{
	int	i;

	data->th = malloc(sizeof(pthread_t) * rules.nbr_philos);
	if (!data->th)
		return (1);
	i = 0;
	while (i < rules.nbr_philos)
	{
		if (pthread_create(&(data->th[i]), NULL, routine, &(data->lst_philos[i])))
			return (1);
		i++;
	}
	return (0);
}

int delete_thread(t_rules rules, t_data *data)
{
	int	i;

	i = 0;
	while (i < rules.nbr_philos)
	{
		if (pthread_join(data->th[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int init_fork(pthread_mutex_t **fork, int nbr)
{
	int i;

	*fork = malloc(sizeof(pthread_mutex_t) * nbr);
	if (!*fork)
		return (1);
	i = 0;
	while(i < nbr)
	{
		if (pthread_mutex_init(&((*fork)[i]), NULL) != 0) // inicio del mutex
		{
			free(*fork);
			return (1);
		}
		i++;
	}
	return (0);
}

int delete_fork(pthread_mutex_t **fork, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_mutex_destroy(&((*fork)[i])) != 0) // finalización del mutex
		{
			free(*fork);
			return (1);
		}
		i++;
	}
	free(*fork);
	return (0);
}
