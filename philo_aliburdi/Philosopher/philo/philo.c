/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:22:21 by aliburdi          #+#    #+#             */
/*   Updated: 2023/03/16 18:42:52 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_everyone(int argc, char **argv, t_everyone *everyone)
{
	everyone->n_ph = ft_atoi(argv[1]);
	everyone->tt_die = ft_atoi(argv[2]);
	everyone->tt_eat = ft_atoi(argv[3]);
	everyone->tt_sleep = ft_atoi(argv[4]);
	everyone->all_ate = 1;
	everyone->some_die = 1;
	if (argc == 6)
		everyone->n_to_eat = ft_atoi(argv[5]);
	else
		everyone->n_to_eat = -1;
	everyone->philo = (t_philo *) malloc (sizeof(t_philo) * everyone->n_ph);
	if (everyone->philo == NULL)
		return (-1);
	if (ft_initmutex(everyone))
		return (-1);
	return (0);
}

static void	init_philo(t_everyone *everyone)
{
	int	i;

	i = 0;
	while (i < everyone->n_ph)
	{
		everyone->philo[i].id = i + 1;
		everyone->philo[i].n_eat = 0;
		everyone->philo[i].end = 0;
		everyone->philo[i].t_starteating = 0;
		everyone->philo[i].everyone = everyone;
		pthread_mutex_init(&everyone->philo[i].strv_mutex, NULL);
		everyone->philo[i].left = &everyone->forks[i];
		everyone->philo[i].right = &everyone->forks[i + 1];
		if (i == everyone->n_ph - 1)
			everyone->philo[i].right = &everyone->forks[0];
		i++;
	}
}

static void	clean(t_everyone *everyone)
{
	int		i;
	t_philo	*philo;

	philo = everyone->philo;
	i = -1;
	while (++i < everyone->n_ph)
		pthread_mutex_destroy(&everyone->forks[i]);
	pthread_mutex_destroy(&everyone->lock);
	pthread_mutex_destroy(&everyone->die_mutex);
	pthread_mutex_destroy(&everyone->eat_mutex);
	pthread_mutex_destroy(&everyone->philo_time);
	free(philo);
	free(everyone->forks);
}

static void	start(t_everyone *everyone)
{
	int	i;

	i = -1;
	everyone->start_time = ft_get_time();
	while (++i < everyone->n_ph)
		pthread_create(&everyone->philo[i].thread, NULL,
			ft_routine, &everyone->philo[i]);
	ft_death(everyone, -1, 0);
	i = -1;
	while (++i < everyone->n_ph)
		pthread_join(everyone->philo[i].thread, NULL);
	clean(everyone);
}

int	main(int argc, char **argv)
{
	t_everyone	everyone;

	if (argc < 5 || argc > 6)
	{
		printf("numero di argomenti errato ❌\n");
		return (-1);
	}
	else
	{
		if (ft_check(argc, argv) || init_everyone(argc, argv, &everyone))
		{
			printf("errore negli argomenti ❌\n");
			return (-1);
		}
		init_philo(&everyone);
		start(&everyone);
	}
}
