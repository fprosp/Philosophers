/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:11 by aliburdi          #+#    #+#             */
/*   Updated: 2023/02/16 04:01:26 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	timestarteating(t_philo *philo)
{
	pthread_mutex_lock(&philo->everyone->philo_time);
	philo->t_starteating = ft_get_time() - philo->everyone->start_time;
	pthread_mutex_unlock(&philo->everyone->philo_time);
}

void	*ft_routine(void *phil)
{
	t_philo	*philo;

	philo = phil;
	if (philo->id % 2 == 0)
		ft_sleep(60);
	while (ft_check_mutex(0, philo))
	{	
		if (ft_take_forks(philo))
			return (NULL);
		timestarteating(philo);
		if (ft_check_mutex(0, philo))
		{
			ft_philo_msg(philo, philo->id, "is eating 🍽");
			ft_sleep(philo->everyone->tt_eat);
		}
		philo->n_eat++;
		if (philo->n_eat == philo->everyone->n_to_eat)
		{
			pthread_mutex_lock(&philo->everyone->eat_mutex);
			philo->end = 1;
			pthread_mutex_unlock(&philo->everyone->eat_mutex);
		}
		ft_action(philo);
	}
	return (NULL);
}
