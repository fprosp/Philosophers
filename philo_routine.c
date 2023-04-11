/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:17 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/11 17:59:31 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	 oth_act(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_dx);
	pthread_mutex_unlock(philo->fork_sx);
	if (death_check(0, philo) != 0)
		print_info(philo, philo->philo_id, "is sleeping ");
	if (death_check(0, philo) != 0)
		get_pause(philo->vars->tt_sleep);
	if (death_check(0, philo))
		print_info(philo, philo->philo_id, "is thinking ");
}

int	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_sx);
	if (death_check(0, philo) != 0)
		print_info(philo, philo->philo_id, "has taken a fork");
	if (philo->vars->n_philos == 1)
		return (EXIT_FAILURE);
	pthread_mutex_lock(philo->fork_dx);
	if (death_check(0, philo) != 0)
		print_info(philo, philo->philo_id, "has taken a fork");
	return (0);
}

void *philo_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		get_pause(60);
	while (death_check(0, philo) != DEATH_SUCCESS)
	{
		if (get_forks(philo) != 0)
			return (NULL);
		eat_time(philo);
		if (death_check(0, philo) != DEATH_SUCCESS)
		{
			print_info(philo, philo->philo_id, "is eating");
			get_pause(philo->vars->tt_eat);
		}
		philo->n_meal++;
		if (philo->n_meal == philo->vars->meal_limit)
		{
			pthread_mutex_lock(&philo->vars->eat_mutex);
			philo->end = 1;
			pthread_mutex_unlock(&philo->vars->eat_mutex);
		}
		oth_act(philo);
	}
	return (NULL);
}
