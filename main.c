/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/31 15:52:16 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		ft_sleep(60);
	
	
}

int philos_cycle_life(t_var *var)
{
	int	i;

	var->start_time = ft_get_time();
	i = -1;
	while (++i < var->n_philo)
		if (pthread_create(var->philo[i].thread, NULL, routine, &var->philo[i]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	i = -1;
	while (++i < var->n_philo)
		pthread_join(var->philo[i].thread, NULL);
	pthread_exit(NULL);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_var var;

	var.argc = argc;
	var.argv = argv;
	if (check_get_init(&var) != EXIT_SUCCESS \
	|| philos_cycle_life(&var) != EXIT_SUCCESS )
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
