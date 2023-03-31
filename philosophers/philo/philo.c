/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:10:19 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 12:16:33 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(int argc, char **argv)
{
	t_context	elem;

	elem.num_philo = ft_atoi(argv[1]);
	elem.time_for_die = ft_atoi(argv[2]);
	elem.time_for_eat = ft_atoi(argv[3]);
	elem.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		elem.cycle = ft_atoi(argv[5]);
	else
		elem.cycle = -1;
	elem.died = 0;
	elem.start_time = get_start_time();
	elem.end = 0;
	sit(&elem);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (usage());
	else
	{
		if (checks(argc, argv) == -1)
			return (-1);
		if (philosophers(argc, argv) != 0)
			return (error());
	}
	return (0);
}
