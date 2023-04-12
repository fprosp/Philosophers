/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/12 14:24:58 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(int i, t_philo *philo)
{
	int	tmp;

	tmp = 0;
	if (i == 0)
	{
		pthread_mutex_lock(&philo->vars->death);
		tmp = philo->vars->some_die;
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

void	oth_act(t_philo *philo)
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

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
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

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	vars.argc = argc;
	vars.argv = argv;
	if (check_n_get(&vars) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	vars.start_time = get_ms_time();
	i = -1;
	while (++i < vars.n_philos)
		pthread_create(&vars.philo[i].ph_thread, \
		NULL, philo_routine, &vars.philo[i]);
	death(&vars, -1, 0);
	i = -1;
	while (++i < vars.n_philos)
		pthread_join(vars.philo[i].ph_thread, NULL);
	free_all(&vars);
	return (EXIT_SUCCESS);
}
