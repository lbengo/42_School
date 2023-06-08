/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:41:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/08 15:41:10 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ***************************** LIBRERIAS ********************************** */

# include <stdio.h>
# include <unistd.h>
# include <pthread.h> // Librería que gestiona las funciones pthread

/* **************************** ESTRUCTURAS ********************************* */

typedef struct s_rules {
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_mut_eat;
}			t_rules;

typedef struct s_philo {
	int				nbr;
	pthread_mutex_t	fork_l;
}			t_philo;

/* ***************************** FUNCIONES ********************************** */

int check_error(int argc, char *argv[]);
int	ft_atoi(const char *str);

#endif
