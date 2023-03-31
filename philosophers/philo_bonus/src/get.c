/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:14 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:06:51 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_fork_id(int i, t_context *elem)
{
	if (i == -1)
		return (elem->num_philos - 1);
	else if (i == elem->num_philos)
		return (0);
	else
		return (i);
}

void	get_philosophers(t_context *elem, t_philos *philos, sem_t *forks)
{
	int		i;

	i = 0;
	while (i < elem->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].dead = 0;
		philos[i].elem = elem;
		philos[i].times_eaten = 0;
		philos[i].last_meal = 0;
		philos[i].forks = forks;
		philos[i].is_dead = 0;
		i++;
	}
}

sem_t	*get_sem(t_context *elem)
{
	sem_t	*ret;

	sem_unlink("/semaphore");
	ret = sem_open("/semaphore", O_CREAT, S_IRWXU, elem->num_philos);
	return (ret);
}
