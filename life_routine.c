/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:59:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/21 18:12:36 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	ft_sleep(uint64_t time)
{
	uint64_t	tmp;

	tmp = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < tmp + time)
		continue ;
}

void life_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*) philo_ptr;
	if (philo->philo_id % 2 != 0)
		ft_sleep(60);
	
	
	return ;
}
