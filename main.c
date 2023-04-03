/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/03 15:04:14 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_var var;
	int i;

	var.argc = argc;
	var.argv = argv;
	if (check_n_get(&var) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	var.time_start = ft_get_time();
	i = -1;
	while (++i < var.n_philo)
		if (pthread_create(var.philo[i].thread, NULL, life_routine, &var.philo[i]) != EXIT_SUCCESS)
			return (free_all(&var));
	i = -1;
	while (++i < var.n_philo)
		pthread_join(var.philo[i].thread, NULL);
	free_all(&var);
	return (EXIT_SUCCESS);
}
