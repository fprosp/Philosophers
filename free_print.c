/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:36:52 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/12 14:24:13 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->vars->lock);
	printf("%llu", get_ms_time() - ph->vars->start_time);
	printf(" %d %s\n", id, str);
	pthread_mutex_unlock(&ph->vars->lock);
}

void	print_death(t_philo *i_philo, int id, char *str)
{
	pthread_mutex_lock(&i_philo->vars->lock);
	printf("%llu", get_ms_time() - i_philo->vars->start_time);
	printf(" %d %s\n", id, str);
}

void	free_structs(t_vars *vars)
{
	t_philo	*philo;

	philo = vars->philo;
	free(philo);
}

void	free_mutex(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n_philos)
		pthread_mutex_destroy(&vars->forks[i]);
	pthread_mutex_destroy(&vars->lock);
	pthread_mutex_destroy(&vars->death);
	pthread_mutex_destroy(&vars->eat);
	pthread_mutex_destroy(&vars->philo_time);
}

int	free_all(t_vars *vars)
{
	free(vars->forks);
	free_mutex(vars);
	free_structs(vars);
	return (EXIT_FAILURE);
}
