/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:19 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:05:50 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sit(t_context *elem)
{
	t_philos	philo[250];
	sem_t		*forks;

	forks = get_sem(elem);
	get_philosophers(elem, philo, forks);
	start_symposium(philo);
}

void	philosophers(int argc, char **argv)
{
	t_context	elem;

	elem.num_philos = ft_atoi(argv[1]);
	elem.time_die = ft_atoi(argv[2]);
	elem.time_eat = ft_atoi(argv[3]);
	elem.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		elem.times_to_eat = ft_atoi(argv[5]);
	else
		elem.times_to_eat = -1;
	elem.some_die = 0;
	elem.finished = 0;
	sem_unlink("/writing_sem");
	elem.writing = sem_open("/writing_sem", O_CREAT, S_IRWXU, 1);
	sem_unlink("/meal_check");
	elem.meal_check = sem_open("/meal_check", O_CREAT, S_IRWXU, 1);
	sit(&elem);
}

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		usage();
	else
	{
		checks(argc, argv);
		philosophers(argc, argv);
	}
	return (0);
}
