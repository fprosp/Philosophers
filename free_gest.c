/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:36:52 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/03 14:43:28 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_fork(t_var *var)
{
    free(var->forks);
    return (EXIT_FAILURE);
}

int free_struct(t_var *var)
{
    t_philo	*philo;

	philo = var->philo;
    free(philo);
    RETURN (EXIT_FAILURE);
}

int free_all(t_var *var)
{
	int i;

	i = -1;
	while (++i < var->n_philo)
		pthread_mutex_destroy(&var->forks[i]);
	pthread_mutex_destroy(&var->lock);
	pthread_mutex_destroy(&var->death);
	pthread_mutex_destroy(&var->eat);
	pthread_mutex_destroy(&var->philo_time);
	free_struct(var);
	free_forks(var);
    return (EXIT_FAILURE);
}