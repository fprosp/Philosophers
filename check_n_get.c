/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/03 14:47:56 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_var *var)
{
	int	i;

	var->philo = (t_philo *)malloc(sizeof(t_philo) * var->n_philo);
	if (!var->philo)
		return (free_fork(var));
	i = -1;
	while (++i < var->n_philo)
	{
		var->philo[i].philo_id = i + 1;
		var->philo[i].n_pasti = 0;
		var->philo[i].fine = 0;
		var->philo[i].t_start_eat = 0;
		var->philo[i].var = var;
		pthread_mutex_init(&var->philo[i].strv_mutex, NULL);
		var->philo[i].fork_sx = &var->forks[i];
		var->philo[i].fork_dx = &var->forks[i + 1];
		if (i == var->n_philo - 1)
			var->philo[i].fork_dx = &var->forks[0];
	}
	return (EXIT_SUCCESS);
}

int var_mutex_init(t_var *var)
{
	int i;
	
	var->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * var->n_philo);
	if (!var->forks)
		return (EXIT_FAILURE);
	i = -1;
    while (++i < var->n_philo)
		pthread_mutex_init(&var->forks[i], NULL);
	pthread_mutex_init(&var->death NULL);
	pthread_mutex_init(&var->lock, NULL);
	pthread_mutex_init(&var->eat, NULL);
	pthread_mutex_init(&var->philo_time, NULL);
	return (EXIT_SUCCESS);
}

int	argv_assign(t_var *var)
{
	int i;
	
	i = 0;
    var->n_philo = ft_atoi(var->argv[1]);
    if (var->n_philo > 200 || var->n_philo <= 0)
        return (EXIT_FAILURE);
    var->time_to_die = ft_atoi(var->argv[2]);
	if (var->time_to_die < 0)
		return (EXIT_FAILURE);
    var->time_to_eat = ft_atoi(var->argv[3]);
	if (var->time_to_eat < 0)
		return (EXIT_FAILURE);
    var->time_to_sleep = ft_atoi(var->argv[4]);
    if (var->time_to_sleep < 0)
        return (EXIT_FAILURE);
    if (var->argc == 6)
    {
	    var->eat_cycle_count = ft_atoi(var->argv[5]);
        if (var->eat_cycle_count < 7)
            return (EXIT_FAILURE);
	}
	var->eat_var = 1;
	var->death_var = 1;
    return (EXIT_SUCCESS);
}

int argv_check(t_var *var)
{
	int i;
	int	j;

	i = 1;
	while (i < var->argc)
	{
		j = 0;
		while (var->argv[i][j] != '\0')
		{
			if ((int)var->argv[i][j] < (int)'0' && (int)var->argv[i][j] > (int)'9')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_n_get(t_var *var)
{
	if (var->argc < 5 || var->argc > 6)
		return (printf("ERROR! Invalid number of values! \
Please reload using following format: \
number_of_philosophers  time_to_die  time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"));
	if (argv_check(var) != EXIT_SUCCESS)
		return (printf("ERROR! You inserted invalid values! \
Please reload and try again"));
	if (argv_assign(var) != EXIT_SUCCESS)
		return (printf("ERROR! The inserted value are out of range! \
Please reload and try again"));
	if (var_mutex_init(var) != EXIT_SUCCESS || philo_init(var) != EXIT_SUCCESS)
		return (printf("ERROR! Wrong memory alloc! \
Please reload and try again"));
	return (EXIT_SUCCESS);
}
