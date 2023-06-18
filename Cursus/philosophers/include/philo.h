/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:41:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/18 18:47:28 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ***************************** LIBRERIAS ********************************** */

# include <stdio.h>
# include <unistd.h>
# include <pthread.h> // Librería que gestiona las funciones pthread
# include <stdlib.h>
# include <sys/time.h> // Librería que gestiona la función gettimeofday

/* **************************** ESTRUCTURAS ********************************* */

typedef struct s_rules {
	long int		start_time;
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_mut_eat;
	pthread_mutex_t *fork;
}	t_rules;

typedef struct s_philo {
	t_rules			*rules;
	int				nbr;
}	t_philo;

typedef struct s_data {
	t_philo			*lst_philos;
	pthread_t		*th;
}	t_data;

/* ***************************** FUNCIONES ********************************** */

/* check_error --------------------------------------------------------------- */
int		check_error(int argc, char *argv[]);

/* Thread ------------------------------------------------------------------- */
int		init_fork(t_rules **rules, int nbr);
int		delete_fork(t_rules **rules, int nbr);
int		create_thread(t_data *data, t_rules *rules);
int		delete_thread(t_data *data, t_rules *rules);

/* Philo_utils -------------------------------------------------------------- */
void	add_rules(t_rules **rules, char *argv[]);
int		add_philos(t_data *data, t_rules *rules);
int		ft_time();

/* Routine -------------------------------------------------------------- */
void	*routine(void *lst_philos);

#endif
