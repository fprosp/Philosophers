/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:47 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:08:40 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

uint64_t	get_time(t_philos *philo, int flag)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (flag)
		philo->last_meal = ((tv.tv_sec) * 1000 + \
			(tv.tv_usec) / 1000) - philo->elem->s_time;
	return (((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000));
}

uint64_t	get_s_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}
