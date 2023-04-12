/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deaths.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:40:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/12 14:11:23 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philokill(t_vars *vars)
{
	pthread_mutex_lock(&vars->death);
	vars->some_die = 0;
	pthread_mutex_unlock(&vars->death);
}

int	all_ate(t_vars *vars, int *n_phil)
{
	if (*n_phil >= vars->n_philos)
	{
		philokill(vars);
		vars->all_ate = 0;
		return (1);
	}
	else
		*n_phil = 0;
	return (0);
}

void	death(t_vars *vars, int i, long long tmp)
{
	t_philo		*philo;
	int			n_phil;

	philo = vars->philo;
	while (1)
	{
		while (++i < vars->n_philos)
		{
			pthread_mutex_lock(&vars->philo_time);
			tmp = get_ms_time() - vars->start_time - philo[i].t_start_eat;
			pthread_mutex_unlock(&vars->philo_time);
			if (tmp > (long long)vars->tt_die)
			{
				philokill(vars);
				print_death(&philo[i], philo[i].philo_id, "died");
				return ;
			}
			if (death_check(1, &philo[i]) != DEATH_SUCCESS)
				n_phil++;
		}
		if (all_ate(vars, &n_phil))
			return ;
		i = -1;
	}
}
