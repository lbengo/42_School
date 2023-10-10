/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:41:31 by lbengoec          #+#    #+#             */
/*   Updated: 2023/09/27 19:07:09 by lbengoec         ###   ########.fr       */
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
	long int		t_start;
	int				nbr_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbr_must_eat;
	int				philo_dead;
	pthread_mutex_t	*fork;
}	t_rules;

typedef struct s_philo {
	t_rules			*rules;
	long int		t_last_eat;
	int				round;
	int				nbr;
}	t_philo;

typedef struct s_data {
	t_philo			*lst_philos;
	pthread_t		*th;
}	t_data;

/* ***************************** FUNCIONES ********************************** */

/* check_error -------------------------------------------------------------- */
int			check_error(int argc, char *argv[]);

/* Thread ------------------------------------------------------------------- */
int			init_fork(t_rules **rules, int nbr);
int			join_thread(t_data *data, t_rules *rules);
int			create_thread(t_data *data, t_rules *rules);
int			delete_fork(t_rules **rules, int nbr);

/* Philo_utils -------------------------------------------------------------- */
long int	ft_time(void);
void		add_rules(t_rules **rules, char *argv[]);
int			add_philos(t_data *data, t_rules **rules);

/* Routine ------------------------------------------------------------------ */
void		*split_routine(void *current_philo);
void		*control_dead(void *general_rules);

/* Routine_utils ------------------------------------------------------------ */
int			check_dead(t_philo *philo);
int			ft_usleep(t_philo *philo, long int time);
int			check_and_print(t_philo *philo, t_rules *rules, char *str);
void		*one_philo(t_philo *philo);

#endif
