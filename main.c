/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 17:27:02 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void start(t_vars *var)
{
	int	i;

	var->start_time = get_time();
	i = 0;
	while (i < var->n_philo)
	{
		
		i++;
	}
	
	return ;
}



int main(int argc, char **argv)
{
	t_vars var;

	var.argc = argc;
	var.argv = argv;
	if (check_get_init(&var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// start(&var);
	return (EXIT_SUCCESS);
}
