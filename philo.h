/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/11 18:52:02 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# define DEATH_SUCCESS 0
# define DEATH_FAILURE 1

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
	int 				argc;
	char				**argv;
	int	 				n_philos;
	uint64_t			start_time;
	uint64_t 			tt_eat;
	uint64_t 			tt_sleep;
	uint64_t 			tt_die;
	int 				meal_limit;
	int 				eat_var;
	int					some_die;
	int					all_ate;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat;
	pthread_mutex_t		death;
	pthread_mutex_t		philo_time;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		lock;
}	t_vars;

int			check_n_get(t_vars *vars);
void		*philo_routine(void *philo_ptr);
void		eat_time(t_philo *philo);
uint64_t	get_ms_time(void);
void		get_pause(uint64_t time);
int			ft_atoi(char *str);
int			death_check(int i, t_philo *philo);
int			free_fork(t_vars *vars);
void 		free_structs(t_vars *vars);
void 		free_mutex(t_vars *vars);
int			free_all(t_vars *vars);
void		print_info(t_philo *ph, int id, char *str);
void		print_death(t_philo *ph, int id, char *str);
void		death(t_vars *vars, int i, long long tmp);
int			death_check(int i, t_philo *philo);

#endif
