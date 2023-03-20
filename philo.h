/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 15:13:47 by fprosper         ###   ########.fr       */
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
	struct s_vars		*var;
	int					id;
	int					n_eat;
	int					end;
	uint64_t			t_starteating;
	pthread_t			thread;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_mutex_t		strv_mutex;
}	t_philo;

typedef struct s_vars
{
	t_philo	*philo;
	int argc;
	char **argv;
	int n_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_count;
}	t_vars;

int		check_n_get(t_vars *var);
int		ascii_to_int(const char *str);

#endif
