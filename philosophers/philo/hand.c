/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:18:01 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 13:42:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	left_hand(t_philo *p)
{
	pthread_mutex_lock(&p->l_fork->mutex);
	pthread_mutex_lock(&p->elem->writing);
	if (!p->elem->end && !p->elem->died)
		printf("%llu %d has taken a fork\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	pthread_mutex_unlock(&p->elem->writing);
	pthread_mutex_lock(&p->r_fork->mutex);
	pthread_mutex_lock(&p->has_eat);
	pthread_mutex_lock(&p->elem->writing);
	if (!p->elem->end && !p->elem->died)
		printf("%llu %d has taken a fork\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	pthread_mutex_unlock(&p->elem->writing);
}

void	right_hand(t_philo *p)
{
	pthread_mutex_lock(&p->r_fork->mutex);
	pthread_mutex_lock(&p->elem->writing);
	if (!p->elem->end && !p->elem->died)
		printf("%llu %d has taken a fork\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	pthread_mutex_unlock(&p->elem->writing);
	pthread_mutex_lock(&p->l_fork->mutex);
	pthread_mutex_lock(&p->has_eat);
	pthread_mutex_lock(&p->elem->writing);
	if (!p->elem->end && !p->elem->died)
		printf("%llu %d has taken a fork\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	pthread_mutex_unlock(&p->elem->writing);
}
