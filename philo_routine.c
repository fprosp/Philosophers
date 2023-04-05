/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:41:00 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/05 13:54:09 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_sx);
	if (ft_check_mutex(0, philo) != 0)
		ft_philo_msg(philo, philo->philo_id, "has taken a fork");
	if (philo->var->n_philo == 1)
		return (1);
	pthread_mutex_lock(philo->fork_dx);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->philo_id, "has taken a fork");
	return (0);
}

int death_rele(int i, t_philo *philo)
{
	int	tmp;

	tmp = 0;
	if (i == 0)
	{
		pthread_mutex_lock(&philo->var->death);
		tmp = philo->var->death_var; // == 1
		pthread_mutex_unlock(&philo->var->death);
	}
	else if (i == 1)
	{
		pthread_mutex_lock(&philo->var->eat);
		tmp = philo->fine; // == 0
		pthread_mutex_unlock(&philo->var->eat);
	}
	return (tmp);
}

void philo_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		ft_sleep(60);
	while (death_rele(0, philo) != 0)
	{
		if (take_forks(philo))
			return (EXIT_FAILURE);
		
	}
	return (EXIT_SUCCESS);
}
