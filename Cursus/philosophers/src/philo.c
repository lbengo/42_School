/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:42:09 by lbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 19:44:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(char *argv[])
{
	t_rules	*rules;
	t_data	data;

	add_rules(&rules, argv);
	if (init_fork(&rules, rules->nbr_philos))
		return (1);
	if (add_philos(&data, &rules))
		return (1);
	if (create_thread(&data, rules))
		return (1);
	if (join_thread(&data, rules))
		return (1);
	if (delete_fork(&rules, rules->nbr_philos))
		return (1);
	free(data.lst_philos);
	free(rules);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (check_error (--argc, ++argv))
		return (1);
	if (philo(argv))
	{
		printf("An error has occurred\n");
		return (1);
	}
	return (0);
}
