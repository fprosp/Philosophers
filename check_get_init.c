/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_get_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/24 17:49:44 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	sum;
	int	sign;
	int	found;

	sum = 0;
	sign = 1;
	found = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (sign * sum);
}

int struct_philos_gen_init(t_vrbs *var)
{
	int	i;

	var->philo = (t_philo *) malloc (sizeof(t_philo) * var->n_philo);
	if (!var->philo)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < var->n_philo)
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
	}
	return (EXIT_SUCCESS) ;
}

int var_assign(t_vrbs *var)
{
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
        var->eat_cycle_count = ft_atoi(var->argv[5]);
        if (var->eat_cycle_count < 7)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int num_check(t_vrbs *var)
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

int	check_get_init(t_vrbs *var)
{
	if (var->argc < 5 || var->argc > 6)
		return (printf("ERROR! ❌ Invalid number of values! \
Please reload using following format: \
number_of_philosophers  time_to_die  time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"));
	if (num_check(var) == EXIT_FAILURE)
		return (printf("ERROR! ❌ You inserted invalid values! \
Please reload and try again"));
    if (var_assign(var) == EXIT_FAILURE)
        return (printf("ERROR! ❌ The inserted incorrect! \
Please reload and try again"));
	if (struct_philos_gen_init(var) == EXIT_FAILURE)
		return (printf("ERROR! ❌ Wrong memory alloc! \
Please reload and try again"));
	return (EXIT_SUCCESS);
}
