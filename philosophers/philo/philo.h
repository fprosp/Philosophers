/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:53:34 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 13:42:43 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef struct s_context
{
	int				num_philo;
	uint64_t		time_for_eat;
	uint64_t		time_for_die;
	int				time_to_sleep;
	int				cycle;
	int				died;
	uint64_t		start_time;
	int				end;
	pthread_mutex_t	writing;
	pthread_t		monitor;

}t_context;

typedef struct s_forks
{
	int				id;
	pthread_mutex_t	mutex;
}t_forks;

typedef struct s_philo
{
	int				id;
	int				dead;
	t_context		*elem;
	t_forks			*l_fork;
	t_forks			*r_fork;
	int				n_eat;
	uint64_t		last_meal;
	pthread_mutex_t	has_eat;
	pthread_t		thread;
}t_philo;

void		ft_putstr(char *s);
int			ft_atoi(const char *str);
long long	ft_atoull(const char *str);

int			usage(void);
int			to_much_philo(void);
int			error_args(void);
int			error(void);
int			error_ui(void);

int			checks(int argc, char **argv);

uint64_t	get_start_time(void);
uint64_t	get_time(t_philo *p, int flag);

void		dont_wake_up(t_philo *pm, uint64_t time);
int			sit(t_context *elem);
void		*monitor(void *philo);
void		*cycle(void *philo);
void		start(t_context *elem, t_philo *philo);

void		get_mutexes(t_context *elem, t_forks *forks);
void		get_philo(t_context *elem, t_philo *philo, t_forks *forks);
void		init_mutexes(t_forks *forks, t_context *elem);
void		kill_mut(t_forks *forks, t_context *elem);

void		left_hand(t_philo *p);
void		right_hand(t_philo *p);

void		kill_philo(t_philo *p);
int			monitor_meals(t_philo *p);
void		message(t_philo *p, int flag);

#endif