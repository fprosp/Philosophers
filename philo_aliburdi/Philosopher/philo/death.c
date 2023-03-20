/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 04:26:37 by aliburdi          #+#    #+#             */
/*   Updated: 2023/02/16 04:27:08 by aliburdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philokill(t_everyone *everyone)
{
	pthread_mutex_lock(&everyone->die_mutex);
	everyone->some_die = 0;
	pthread_mutex_unlock(&everyone->die_mutex);
}

static int	all_ate(t_everyone *everyone, int *howmanyphilo)
{
	if (*howmanyphilo >= everyone->n_ph)
	{
		philokill(everyone);
		everyone->all_ate = 0;
		return (1);
	}
	else
		*howmanyphilo = 0;
	return (0);
}

static void	print_die(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->everyone->lock);
	printf("%llu", ft_get_time() - ph->everyone->start_time);
	printf(" %d %s\n", id, str);
}

void	ft_death(t_everyone *everyone, int i, long long tmp)
{
	t_philo		*philo;
	int			howmanyphilo;

	philo = everyone->philo;
	while (1)
	{
		while (++i < everyone->n_ph)
		{
			pthread_mutex_lock(&everyone->philo_time);
			tmp = ft_get_time() - everyone->start_time - philo[i].t_starteating;
			pthread_mutex_unlock(&everyone->philo_time);
			if (tmp > (long long) everyone->tt_die)
			{
				philokill(everyone);
				print_die(&philo[i], philo[i].id, "died 😵");
				return ;
			}
			if (ft_check_mutex(1, &philo[i]))
				howmanyphilo++;
		}
		if (all_ate(everyone, &howmanyphilo))
			return ;
		i = -1;
	}
}
