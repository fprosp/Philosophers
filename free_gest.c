/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:36:52 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 17:30:34 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_fork(t_vars *vars)
{
    free(vars->forks);
    return (EXIT_FAILURE);
}

void free_struct(t_vars *vars)
{
    t_philo	*philo;

	philo = vars->philo;
    free(philo);
}

int free_all(t_vars *vars)
{
	int i;

	i = -1;
	while (++i < vars->n_philos)
		pthread_mutex_destroy(&vars->forks[i]);
	pthread_mutex_destroy(&vars->lock);
	pthread_mutex_destroy(&vars->death);
	pthread_mutex_destroy(&vars->eat);
	pthread_mutex_destroy(&vars->philo_time);
	free_struct(vars);
	free_forks(vars);
    return (EXIT_FAILURE);
}