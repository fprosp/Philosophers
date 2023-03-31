/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:53:50 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 12:18:54 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(t_philo *p, int flag)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (flag)
		p->last_meal = (t.tv_sec * 1000
				+ t.tv_usec / 1000) - p->elem->start_time;
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

uint64_t	get_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
