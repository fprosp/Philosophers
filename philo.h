/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/31 15:55:15 by fprosper         ###   ########.fr       */
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
	struct s_var		*var;
	int					philo_id;
	int					n_meal;
	uint64_t			t_starteating;
	pthread_t			thread;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_mutex_t		*forks;
	pthread_mutex_t		strv_mutex;
	int					the_end;
}	t_philo;

typedef struct s_var
{
	t_philo				*philo;
	pthread_mutex_t		*forks;
	int 				argc;
	char				**argv;
	int	 				n_philo;
	int 				time_to_die;
	int 				time_to_eat;
	int 				time_to_sleep;
	int 				eat_cycle_count;
	uint64_t			start_time;
}	t_var;

int			check_get_init(t_vrbs *var);
void		life_routine(void *philo_ptr);
uint64_t	ft_get_time(void);
void		ft_usleep(uint64_t time);
void		life_cycle(void *philo_ptr);


#endif
