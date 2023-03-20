/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:34:41 by aliburdi          #+#    #+#             */
/*   Updated: 2023/02/16 04:32:19 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_everyone	*everyone;
	int					id;
	int					n_eat;
	int					end;
	uint64_t			t_starteating;
	pthread_t			thread;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_mutex_t		strv_mutex;

}				t_philo;

typedef struct s_everyone
{
	int				n_ph;
	uint64_t		tt_die;
	uint64_t		tt_eat;
	uint64_t		tt_sleep;
	int				n_to_eat;
	int				some_die;
	int				all_ate;
	uint64_t		start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	philo_time;
	pthread_mutex_t	lock;
}	t_everyone;

int			ft_check(int argc, char **argv);
long long	ft_atoi(const char *str);
void		ft_sleep(uint64_t time);
void		ft_philo_msg(t_philo *ph, int id, char *str);
int			ft_initmutex(t_everyone *everyone);
uint64_t	ft_get_time(void);
void		*ft_routine(void *phil);
void		ft_death(t_everyone *everyone, int i, long long tmp);
int			ft_take_forks(t_philo *philo);
void		ft_action(t_philo *philo);
int			ft_check_mutex(int flag, t_philo *philo);

#endif