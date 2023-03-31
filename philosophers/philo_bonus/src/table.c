/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:43 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:10:18 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_them_all(t_philos *philos)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < philos[0].elem->num_philos)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < philos[0].elem->num_philos)
				kill(philos[i].pid, 15);
			break ;
		}
		i++;
	}
}

void	start_symposium(t_philos *philos)
{
	int	i;

	i = -1;
	philos[0].elem->s_time = get_s_time();
	while (++i < philos[0].elem->num_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid < 0)
			die("Fork error");
		if (!philos[i].pid)
			born_child(&philos[i]);
		usleep(50);
	}
	kill_them_all(philos);
	sem_close(philos[0].elem->writing);
	sem_close(philos[0].forks);
	sem_unlink("/writing_sem");
	sem_unlink("/semaphore");
	sem_unlink("/meal_check");
}
