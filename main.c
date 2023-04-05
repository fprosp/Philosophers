/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/05 13:54:04 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_vars vars;
	int i;

	vars.argc = argc;
	vars.argv = argv;
	if (check_n_get(&vars) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	vars.time_start = ft_get_time();
	i = -1;
	while (++i < vars.n_philo)
		if (pthread_create(vars.philo[i].thread, NULL, philo_routine, &vars.philo[i]) != EXIT_SUCCESS)
			return (free_all(&vars));
	i = -1;
	while (++i < vars.n_philo)
		pthread_join(vars.philo[i].thread, NULL);
	free_all(&vars);
	return (EXIT_SUCCESS);
}
