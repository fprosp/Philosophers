/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 15:13:20 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int struct_philos_gen(t_vars *var)
{
	var->philo = (t_philo *) malloc (sizeof(t_philo) * var->n_philo);
	if (!var->philo)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int var_assign(t_vars *var)
{
    var->n_philo = ascii_to_int(var->argv[1]);
    if (var->n_philo > 200 || var->n_philo <= 0)
        return (1);
    var->time_to_die = ascii_to_int(var->argv[2]);
	if (var->time_to_die < 0)
		return (1);
    var->time_to_eat = ascii_to_int(var->argv[3]);
	if (var->time_to_eat < 0)
		return (1);
    var->time_to_sleep = ascii_to_int(var->argv[4]);
    if (var->time_to_sleep < 0)
        return (1);
    if (var->argc == 6)
        var->eat_count = ascii_to_int(var->argv[5]);
        if (var->eat_count < 7)
            return (1);
	else
		var->eat_count = -1;
    return (0);
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
			if ((int)var->argv[i][j] < 48  && (int)var->argv[i][j] > 57)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_n_get(t_vars *var)
{
	if (var->argc < 5 || var->argc > 6)
	{
		printf("Invalid number of values! Please try again with 4 or 5 arguments\n");
		return (EXIT_FAILURE);
	}
	if (num_check(var) == EXIT_FAILURE)
	{
		printf("You inserted invalid values! Please reolad and try again\n");
		return (EXIT_FAILURE);
	}
    if (var_assign(var) == EXIT_FAILURE)
	{
		printf("The inserted incorrect! Please reolad and try again\n");
        return (EXIT_FAILURE);
	}
	if (struct_philos_gen(var) == EXIT_FAILURE)
	{
		printf("Wrong memory alloc! Please reolad and try again\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
