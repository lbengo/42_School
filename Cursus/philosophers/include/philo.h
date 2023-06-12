/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurabengoechea <laurabengoechea@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:41:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/06/12 15:07:42 by laurabengoe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ***************************** LIBRERIAS ********************************** */

# include <stdio.h>
# include <unistd.h>
# include <pthread.h> // Librería que gestiona las funciones pthread
# include <stdlib.h>

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
	pthread_mutex_t	fork_r;
}			t_philo;

typedef struct s_data {
	t_philo			*lst_philos;
	pthread_t		*th;
	pthread_mutex_t	*fork;
}			t_data;


/* ***************************** FUNCIONES ********************************** */

/* Thread ------------------------------------------------------------------- */
int check_error(int argc, char *argv[]);

/* Thread ------------------------------------------------------------------- */
int create_thread(t_rules rules, t_data *data);
int delete_thread(t_rules rules, t_data *data);
int init_fork(pthread_mutex_t **fork, int nbr);
int delete_fork(pthread_mutex_t **fork, int nbr);

/* Philo_utils -------------------------------------------------------------- */
t_rules	add_rules(char *argv[]);
int	add_philos(int n_philos, t_data *data);


#endif
