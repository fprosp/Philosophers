/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 15:56:50 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void var_init(t_vars *var)
{
	int	i;

	i = 0;
	while (i < var->n_philo)
	{
		var->philo[i].philo_id = i + 1;
		var->philo[i].n_meal = 0;
		var->philo[i].the_end = 0;
		var->philo[i].t_starteating = 0;
		var->philo[i].var = var;
		pthread_mutex_init(&var->philo[i].strv_mutex, NULL);
		var->philo[i].left = &var->forks[i];
		var->philo[i].right = &var->forks[i + 1];
		if (i == var->n_philo - 1)
			var->philo[i].right = &var->forks[0];
		i++;
	}
	return ;
}

int struct_philos_gen_init(t_vars *var)
{
	var->philo = (t_philo *) malloc (sizeof(t_philo) * var->n_philo);
	if (!var->philo)
		return (EXIT_FAILURE);
	var_init(var);
	return (EXIT_SUCCESS);
}

int var_assign(t_vars *var)
{
    var->n_philo = ascii_to_int(var->argv[1]);
    if (var->n_philo > 200 || var->n_philo <= 0)
        return (EXIT_FAILURE);
    var->time_to_die = ascii_to_int(var->argv[2]);
	if (var->time_to_die < 0)
		return (EXIT_FAILURE);
    var->time_to_eat = ascii_to_int(var->argv[3]);
	if (var->time_to_eat < 0)
		return (EXIT_FAILURE);
    var->time_to_sleep = ascii_to_int(var->argv[4]);
    if (var->time_to_sleep < 0)
        return (EXIT_FAILURE);
    if (var->argc == 6)
        var->eat_count = ascii_to_int(var->argv[5]);
        if (var->eat_count < 7)
            return (EXIT_FAILURE);
	else
		var->eat_count = -1;
    return (EXIT_SUCCESS);
}

int num_check(t_vars *var)
{
	int i;
	int	j;

	i = 1;
	while (i <= var->argc)
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

int	check_get_init(t_vars *var)
{
	if (var->argc < 5 || var->argc > 6)
	{
		printf("Invalid number of values! ❌ Please reload with 4 or 5 arguments");
		return (EXIT_FAILURE);
	}
	if (num_check(var) == EXIT_FAILURE)
	{
		printf("You inserted invalid values! ❌ Please reload and try again");
		return (EXIT_FAILURE);
	}
    if (var_assign(var) == EXIT_FAILURE)
	{
		printf("The inserted incorrect! ❌ Please reload and try again");
        return (EXIT_FAILURE);
	}
	if (struct_philos_gen_init(var) == EXIT_FAILURE)
	{
		printf("Wrong memory alloc! ❌ Please reload and try again");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
