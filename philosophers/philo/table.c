/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:45:48 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 13:43:23 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dont_wake_up(t_philo *p, uint64_t time)
{
	uint64_t	start;

	start = get_time(p, 0) - p->elem->start_time;
	while (!p->elem->died)
	{
		if (get_time(p, 0) - p->elem->start_time - start > time)
			break ;
		usleep(10);
	}
}

int	sit(t_context *elem)
{
	t_philo	philo[250];
	t_forks	forks[250];

	get_mutexes(elem, forks);
	get_philo(elem, philo, forks);
	init_mutexes(forks, elem);
	start(elem, philo);
	kill_mut(forks, elem);
	return (0);
}

void	*monitor(void *philo)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philo;
	while (!p[0].elem->end)
	{
		i = -1;
		while (++i < p[0].elem->num_philo)
		{
			pthread_mutex_lock(&p[i].has_eat);
			if (get_time(&p[0], 0) - p[0].elem->start_time
				- p[i].last_meal > p[0].elem->time_for_die)
			{
				kill_philo(&p[i]);
				return (NULL);
			}
			pthread_mutex_unlock(&p[i].has_eat);
		}
		if (p[0].elem->cycle != -1 && !p[0].elem->died
			&& monitor_meals(p))
			p[0].elem->end = 1;
	}
	return (NULL);
}

void	*cycle(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (!p->elem->end && !p->elem->died)
	{
		if (p->id % 2 == 0)
			left_hand(p);
		else
			right_hand(p);
		message(p, 0);
		p->n_eat++;
		pthread_mutex_unlock(&p->has_eat);
		dont_wake_up(p, p->elem->time_for_eat);
		pthread_mutex_unlock(&p->l_fork->mutex);
		pthread_mutex_unlock(&p->r_fork->mutex);
		message(p, 1);
		dont_wake_up(p, p->elem->time_to_sleep);
		message(p, 2);
	}
	return (NULL);
}

void	start(t_context *elem, t_philo *philo)
{
	int	i;

	pthread_create(&elem->monitor, NULL, &monitor, (void *)philo);
	i = -1;
	while (++i < elem->num_philo)
	{
		pthread_create(&philo[i].thread, NULL, &cycle, &philo[i]);
		usleep(500);
	}
	pthread_join(elem->monitor, NULL);
}
