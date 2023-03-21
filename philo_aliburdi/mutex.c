/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:37 by aliburdi          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:14 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initmutex(t_everyone *everyone)
{
	int	i;

	i = 0;
	pthread_mutex_init(&everyone->die_mutex, NULL);
	pthread_mutex_init(&everyone->lock, NULL);
	pthread_mutex_init(&everyone->eat_mutex, NULL);
	pthread_mutex_init(&everyone->philo_time, NULL);
	everyone->forks = (pthread_mutex_t *) malloc
		(sizeof(pthread_mutex_t) * everyone->n_ph);
	if (!everyone->forks)
		return (-1);
	while (i < everyone->n_ph)
		pthread_mutex_init(&everyone->forks[i++], NULL);
	return (0);
}

int	ft_check_mutex(int flag, t_philo *philo)
{
	int	tmp;

	tmp = 0;
	if (flag == 0)
	{
		pthread_mutex_lock(&philo->everyone->die_mutex);
		tmp = philo->everyone->some_die;
		pthread_mutex_unlock(&philo->everyone->die_mutex);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(&philo->everyone->eat_mutex);
		tmp = philo->end;
		pthread_mutex_unlock(&philo->everyone->eat_mutex);
	}
	return (tmp);
}
