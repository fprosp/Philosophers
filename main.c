/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/07 17:34:03 by fprosper         ###   ########.fr       */
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
	vars.start_time = get_milli_time();
	i = -1;
	while (++i < vars.n_philos)
		if (pthread_create(vars.philo[i].ph_thread, NULL, philo_routine, &vars.philo[i]) != EXIT_SUCCESS)
			return (free_all(&vars));
	deaths(vars, -1, 0);
	i = -1;
	while (++i < vars.n_philos)
		pthread_join(vars.philo[i].ph_thread, NULL);
	free_all(&vars);
	return (EXIT_SUCCESS);
}
