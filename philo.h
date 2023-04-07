/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 16:40:58 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# define DEATH_SUCCESS 1
# define DEATH_FAILURE 0

typedef struct s_philo
{
	struct s_vars		*vars;
	int					philo_id;
	int					n_meal;
	int					end;
	uint64_t			t_start_eat;
	pthread_t			ph_thread;
	pthread_mutex_t		*fork_sx;
	pthread_mutex_t		*fork_dx;
	pthread_mutex_t		strv_mutex;
}	t_philo;

typedef struct s_vars
{
	t_philo				*philo;
	uint64_t			start_time;
	int 				argc;
	char				**argv;
	int 				death_var;
	int	 				n_philos;
	int 				tt_eat;
	int 				tt_sleep;
	int 				tt_die;
	int 				n_to_eat;
	int 				eat_var;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat;
	pthread_mutex_t		death;
	pthread_mutex_t		philo_time;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		lock;
}	t_vars;

int			check_get_init(t_vars *vars);
void		philo_routine(void *philo_ptr);
int			free_fork(t_vars *vars);
int 		free_struct(t_vars *vars);
int			free_all(t_vars *vars);

uint64_t	get_milli_time(void);
void		ppause(uint64_t time);

#endif
