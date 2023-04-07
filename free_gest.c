/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:36:52 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 16:38:36 by fprosper         ###   ########.fr       */
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