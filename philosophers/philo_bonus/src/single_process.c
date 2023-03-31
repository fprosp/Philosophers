/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:32 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:10:03 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	monitor_meals(t_philos *philos)
{
	if (philos->times_eaten < philos->elem->times_to_eat)
		return (0);
	return (1);
}

void	*monitor(void *philos)
{
	t_philos	*p;

	p = (t_philos *)philos;
	while (!p->elem->finished)
	{
		sem_wait(p->elem->meal_check);
		if (get_time(p, 0) - p->elem->s_time
			- p->last_meal >= p->elem->time_die)
		{
			p->elem->some_die = 1;
			sem_wait(p->elem->writing);
			printf("%llu %d died\n", get_time(p, 0) - p->elem->s_time, p->id);
			exit(1);
		}
		sem_post(p->elem->meal_check);
		if (p->elem->times_to_eat != -1 && monitor_meals(p))
			p->elem->finished = 1;
		usleep(500);
	}
	return (NULL);
}

void	take_fork(t_philos *p)
{
	sem_wait(p->forks);
	sem_wait(p->elem->writing);
	if (!p->elem->finished && !p->elem->some_die)
		printf("%llu %d has taken a fork\n", get_time(p, 0)
			- p->elem->s_time, p->id);
	sem_post(p->elem->writing);
}

void	born_child(t_philos *philo)
{
	pthread_create(&philo->elem->monitor, NULL, &monitor, (void *)philo);
	while (!philo->elem->some_die && !philo->elem->finished)
	{
		take_fork(philo);
		if (philo->elem->num_philos > 1)
			take_fork(philo);
		sem_wait(philo->elem->meal_check);
		write_message(philo, 0);
		philo->times_eaten++;
		sem_post(philo->elem->meal_check);
		dont_wake_up(philo, philo->elem->time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		write_message(philo, 1);
		dont_wake_up(philo, philo->elem->time_sleep);
		write_message(philo, 2);
	}
	if (philo->elem->some_die)
		exit(1);
	exit(0);
	return ;
}
