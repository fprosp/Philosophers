/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:41:00 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/03 14:57:01 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int death_rele(int i, t_philo *philo)
{
	int	tmp;

	tmp = 0;
	if (i == 0)
	{
		pthread_mutex_lock(&philo->var->death);
		tmp = philo->var->death_var;
		pthread_mutex_unlock(&philo->var->death);
	}
	else if (i == 1)
	{
		pthread_mutex_lock(&philo->var->eat);
		tmp = philo->fine;
		pthread_mutex_unlock(&philo->var->eat);
	}
	return (tmp);
}

void life_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		ft_sleep(60);
	while (death_rele(0, philo) != 0)
	{
		
	}
	return (EXIT_SUCCESS);
}
