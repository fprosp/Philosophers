/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:24:06 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 13:36:50 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork_id(int i, t_context *elem)
{
	if (i == -1)
		return (elem->num_philo - 1);
	else if (i == elem->num_philo)
		return (0);
	return (i);
}

void	get_philo(t_context *elem, t_philo *philo, t_forks *forks)
{
	int	i;

	i = 0;
	while (i < elem->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].elem = elem;
		philo[i].l_fork = &forks[get_fork_id(i + 1, elem)];
		philo[i].r_fork = &forks[get_fork_id(i, elem)];
		philo[i].n_eat = 0;
		philo[i].last_meal = 0;
		pthread_mutex_init(&philo[i].has_eat, NULL);
		i++;
	}
}

void	get_mutexes(t_context *elem, t_forks *forks)
{
	int	i;

	i = 0;
	while (i < elem->num_philo * 2)
	{
		forks[i].id = i;
		i++;
	}
}

void	init_mutexes(t_forks *forks, t_context *elem)
{
	int	i;

	i = 0;
	while (i < elem->num_philo)
		pthread_mutex_init(&forks[i++].mutex, NULL);
	pthread_mutex_init(&elem->writing, NULL);
}

void	kill_mut(t_forks *forks, t_context *elem)
{
	int	i;

	i = 0;
	while (i < elem->num_philo)
		pthread_mutex_destroy(&forks[i++].mutex);
	pthread_mutex_destroy(&elem->writing);
}
