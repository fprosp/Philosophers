/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:11 by aliburdi          #+#    #+#             */
/*   Updated: 2023/03/21 16:34:32 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	timestarteating(t_philo *philo)
{
	pthread_mutex_lock(&philo->everyone->philo_time);
	philo->t_starteating = ft_get_time() - philo->everyone->start_time;
	pthread_mutex_unlock(&philo->everyone->philo_time);
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

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "has taken a fork 🍴");
	if (philo->everyone->n_ph == 1)
		return (1);
	pthread_mutex_lock(philo->right);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "has taken a fork 🍴");
	return (0);
}

void	ft_philo_msg(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->everyone->lock);
	printf("%llu", ft_get_time() - ph->everyone->start_time);
	printf(" %d %s\n", id, str);
	pthread_mutex_unlock(&ph->everyone->lock);
}

void	ft_sleep(uint64_t time)
{
	uint64_t	tmp;

	tmp = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < tmp + time)
		continue ;
}

void	 ft_action(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "is sleeping 💤");
	if (ft_check_mutex(0, philo))
		ft_sleep(philo->everyone->tt_sleep);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "is thinking 🤔");
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
