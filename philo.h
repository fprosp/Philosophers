/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/05 13:54:15 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					philo_id;
	int					n_pasti;
	int					fine;
	uint64_t			t_start_eat;
	pthread_t			thread;
	pthread_mutex_t		*fork_sx;
	pthread_mutex_t		*fork_dx;
	pthread_mutex_t		strv_mutex;
	struct s_var		*var;
}	t_philo;

typedef struct s_vars
{
	t_philo				*philo;
	int 				argc;
	char				**argv;
	uint64_t			time_start;
	int	 				n_philo;
	int 				time_to_die;
	int 				time_to_eat;
	int 				time_to_sleep;
	int 				eat_cycle_count;
	int 				death_var;
	int 				eat_var;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat;
	pthread_mutex_t		death;
	pthread_mutex_t		philo_time;
	pthread_mutex_t		lock;
}	t_vars;

int			check_get_init(t_var *var);
void		philo_routine(void *philo_ptr);
int			free_fork(t_var *var);
int 		free_struct(t_var *var);
int			free_all(t_var *var);

uint64_t	egit_get_time(void);
void		edit_usleep(uint64_t time);

#endif
