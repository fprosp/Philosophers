/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:43:14 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 13:42:41 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_philo *p)
{
	p->elem->died = 1;
	pthread_mutex_lock(&p[0].elem->writing);
	printf("%llu %d died\n", get_time(&p[0], 0)
		- p[0].elem->start_time, p->id);
	return ;
}

int	monitor_meals(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p[0].elem->num_philo)
	{
		if (p[i].n_eat < p[i].elem->cycle)
			return (0);
	}
	return (1);
}

void	message(t_philo *p, int flag)
{
	pthread_mutex_lock(&p->elem->writing);
	if (!flag && !p->elem->died && !p->elem->end)
		printf("%llu %d is eating\n", get_time(p, 1)
			- p->elem->start_time, p->id);
	else if (flag == 1 && !p->elem->died && !p->elem->end)
		printf("%llu %d is sleeping\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	else if (flag == 2 && !p->elem->died && !p->elem->end)
		printf("%llu %d is thinking\n", get_time(p, 0)
			- p->elem->start_time, p->id);
	pthread_mutex_unlock(&p->elem->writing);
}
