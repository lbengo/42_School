/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:28:02 by laurabengoe       #+#    #+#             */
/*   Updated: 2023/06/18 18:39:51 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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
	(*rules)->start_time = ft_time();
	(*rules)->nbr_philos = ft_atoi(argv[0]);
	(*rules)->time_to_die = ft_atoi(argv[1]);
	(*rules)->time_to_eat = ft_atoi(argv[2]);
	(*rules)->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		(*rules)->nbr_mut_eat = ft_atoi(argv[4]);
}

int	add_philos(t_data *data, t_rules rules)
{
	int	nbr;

	data->lst_philos = malloc(sizeof(t_philo) * rules.nbr_philos);
	if (!data->lst_philos)
		return (1);
	nbr = 0;
	while (nbr < rules.nbr_philos)
	{
		data->lst_philos[nbr].rules = &rules;
		data->lst_philos[nbr].nbr = nbr + 1;
		nbr++;
	}
	return (0);
}
