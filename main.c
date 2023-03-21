/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/21 17:04:00 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void phtread_life(t_vars *var)
{
	int	i;

	var->start_time = ft_get_time();
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
