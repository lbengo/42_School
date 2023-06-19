/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:28:02 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/19 19:09:46 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time(long int t_start)
{
	struct timeval	time;
	long int		t_current;

	gettimeofday(&time, NULL);
	t_current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (t_current - t_start);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + str[i] - '0';
		i++;
	}
	return (count);
}

void	add_rules(t_rules **rules, char *argv[])
{
	*rules = (t_rules *) malloc(sizeof(t_rules) * 1);
	(*rules)->t_start = ft_time(0);
	(*rules)->nbr_philos = ft_atoi(argv[0]);
	(*rules)->t_die = ft_atoi(argv[1]);
	(*rules)->t_eat = ft_atoi(argv[2]);
	(*rules)->t_sleep = ft_atoi(argv[3]);
	(*rules)->philo_dead = 0;
	if (argv[4])
		(*rules)->nbr_mut_eat = ft_atoi(argv[4]);
}

int	add_philos(t_data *data, t_rules **rules)
{
	int	nbr;

	data->lst_philos = malloc(sizeof(t_philo) * (*rules)->nbr_philos);
	if (!data->lst_philos)
		return (1);
	nbr = 0;
	while (nbr < (*rules)->nbr_philos)
	{
		data->lst_philos[nbr].rules = (*rules);
		data->lst_philos[nbr].nbr = nbr + 1;
		nbr++;
	}
	return (0);
}
