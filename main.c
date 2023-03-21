/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/21 16:32:39 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void life_routine(void *philo_ptr)
{
	t_philo *philo;
	
	philo = (t_philo*) philo_ptr;
	if (philo->philo_id % 2 != 0)
		ft_sleep(60);
	
	return ;
}

void phtread_life(t_vars *var)
{
	int	i;
	uint64_t time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	var->start_time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	i = 0;
	while (i < var->n_philo)
	{
		pthread_create(var->philo[i].thread, NULL, life_routine, &var->philo[i]);
		i++;
	}
	i = 0;
	while (i < var->n_philo)
	{
		pthread_join(var->philo[i].thread, NULL);
		i++;
	}

	return ;
}

int main(int argc, char **argv)
{
	t_vars var;

	var.argc = argc;
	var.argv = argv;
	if (check_get_init(&var) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	phtread_life(&var);

	return (EXIT_SUCCESS);
}
