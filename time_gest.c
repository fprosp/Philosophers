/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:18:58 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 16:36:38 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_time_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->philo_time);
	philo->t_start_eat = get_milli_time() - philo->vars->start_time;
	pthread_mutex_unlock(&philo->vars->philo_time);
}

uint64_t	get_milli_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	ppause(uint64_t time)
{
	uint64_t	tmp;

	tmp = get_milli_time();
	usleep(time * 1000 - 20000);
	while (get_milli_time() < tmp + time)
		continue ;
}

