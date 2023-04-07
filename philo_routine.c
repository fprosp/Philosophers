/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:39:17 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 17:38:06 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->vars->lock);
	printf("%llu", get_milli_time() - ph->vars->start_time);
	printf(" %d %s\n", id, str);
	pthread_mutex_unlock(&ph->vars->lock);
}

int death_check(int i, t_philo *philo)
{
	int	tmp;

	tmp = 0;
	if (i == 0)
	{
		pthread_mutex_lock(&philo->vars->death);
		tmp = philo->vars->death_var;
		pthread_mutex_unlock(&philo->vars->death);
	}
	else if (i == 1)
	{
		pthread_mutex_lock(&philo->vars->eat);
		tmp = philo->end;
		pthread_mutex_unlock(&philo->vars->eat);
	}
	return (tmp);
}

void	 oth_act(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_dx);
	pthread_mutex_unlock(philo->fork_sx);
	if (death_check(0, philo) != 0)
		ft_philo_msg(philo, philo->philo_id, "is sleeping ");
	if (death_check(0, philo) != 0)
		ft_sleep(philo->vars->tt_sleep);
	if (death_check(0, philo))
		ft_philo_msg(philo, philo->philo_id, "is thinking ");
}

int	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_sx);
	if (death_check(0, philo) != DEATH_SUCCESS)
		print(philo, philo->philo_id, "has taken a fork");
	if (philo->vars->n_philos == 1)
		return (EXIT_FAILURE);
	pthread_mutex_lock(philo->fork_dx);
	if (death_check(0, philo) != DEATH_SUCCESS)
		print(philo, philo->philo_id, "has taken a fork");
	return (0);
}

void philo_routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		ppause(60);
	while (death_check(0, philo) != DEATH_SUCCESS)
	{
		if (get_forks(philo) != 0)
			return (NULL);
		get_time_eat(philo);
		if (death_check(0, philo) != 0)
		{
			print(philo, philo->philo_id, "is eating ");
			ppause(philo->vars->tt_eat);
		}
		philo->n_meal++;
		if (philo->n_meal == philo->vars->n_to_eat)
		{
			pthread_mutex_lock(&philo->vars->eat_mutex);
			philo->end = 1;
			pthread_mutex_unlock(&philo->vars->eat_mutex);
		}
		oth_act(philo);
	}
	return (EXIT_SUCCESS);
}
