/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 16:30:32 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_init(t_vars *vars)
{
	int i;

	vars->philo = (t_philo *)malloc(sizeof(t_philo) * vars->n_philos);
	if (!vars->philo)
		return (free_fork(vars));
	i = -1;
	while (++i < vars->n_philos)
	{
		vars->philo[i].philo_id = i + 1;
		vars->philo[i].n_pasti = 0;
		vars->philo[i].fine = 0;
		vars->philo[i].t_start_eat = 0;
		vars->philo[i].eat_var = vars;
		pthread_mutex_init(&vars->philo[i].strv_mutex, NULL);
		vars->philo[i].fork_sx = &vars->forks[i];
		vars->philo[i].fork_dx = &vars->forks[i + 1];
		if (i == vars->n_philos - 1)
			vars->philo[i].fork_dx = &vars->forks[0];
	}
	return (EXIT_SUCCESS);
}

int var_mutex_init(t_vars *vars)
{
	int i;

	vars->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * vars->n_philos);
	if (!vars->forks)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < vars->n_philos)
		pthread_mutex_init(&vars->forks[i], NULL);
	pthread_mutex_init(&vars->death NULL);
	pthread_mutex_init(&vars->lock, NULL);
	pthread_mutex_init(&vars->eat, NULL);
	pthread_mutex_init(&vars->philo_time, NULL);
	return (EXIT_SUCCESS);
}

int argv_assign(t_vars *vars)
{
	int i;

	i = 0;
	vars->n_philos = ft_atoi(vars->argv[1]);
	if (vars->n_philos > 200 || vars->n_philos <= 0)
		return (EXIT_FAILURE);
	vars->tt_die = ft_atoi(vars->argv[2]);
	if (vars->tt_die < 0)
		return (EXIT_FAILURE);
	vars->tt_eat = ft_atoi(vars->argv[3]);
	if (vars->tt_eat < 0)
		return (EXIT_FAILURE);
	vars->tt_sleep = ft_atoi(vars->argv[4]);
	if (vars->tt_sleep < 0)
		return (EXIT_FAILURE);
	if (vars->argc == 6)
	{
		vars->eat_cycle_count = ft_atoi(vars->argv[5]);
		if (vars->eat_cycle_count < 7)
			return (EXIT_FAILURE);
	}
	vars->eat_var = 1;
	vars->death_var = 1;
	return (EXIT_SUCCESS);
}

int argv_check(t_vars *vars)
{
	int i;
	int j;

	i = 1;
	while (i < vars->argc)
	{
		j = 0;
		while (vars->argv[i][j] != '\0')
		{
			if ((int)vars->argv[i][j] < (int)'0' && (int)vars->argv[i][j] > (int)'9')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int check_n_get(t_vars *vars)
{
	if (vars->argc < 5 || vars->argc > 6)
		return (printf("ERROR! Invalid number of values! \
Please reload using following format: \
number_of_philosophers  tt_die  tt_eat tt_sleep \
[number_of_times_each_philosopher_must_eat]"));
	if (argv_check(vars) != EXIT_SUCCESS)
		return (printf("ERROR! You inserted invalid values! \
Please reload and try again"));
	if (argv_assign(vars) != EXIT_SUCCESS)
		return (printf("ERROR! The inserted value are out of range! \
Please reload and try again"));
	if (var_mutex_init(vars) != EXIT_SUCCESS || philo_init(vars) != EXIT_SUCCESS)
		return (printf("ERROR! Wrong memory alloc! \
Please reload and try again"));
	return (EXIT_SUCCESS);
}
