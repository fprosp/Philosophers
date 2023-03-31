/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:53 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:10:03 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while ((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == 32)
		i++;
	if (*(str + i) == 43 || *(str + i) == 45)
	{
		if (*(str + i) == 45)
			sign *= -1;
		i++;
	}
	if (*(str + i) == 43 || *(str + i) == 45)
		return (0);
	while (*(str + i) > 47 && *(str + i) < 58)
	{
		ret = (ret * 10) + (*(str + i) - 48);
		i++;
	}
	return (ret * sign);
}

void	dont_wake_up(t_philos *philo, uint64_t time)
{
	uint64_t	start;

	start = get_time(philo, 0) - philo->elem->s_time;
	while (!philo->elem->some_die)
	{
		if ((get_time(philo, 0) - philo->elem->s_time) - start >= time)
			break ;
		usleep(10);
	}
}

void	write_message(t_philos *philo, int flag)
{
	sem_wait(philo->elem->writing);
	if (!flag && !philo->elem->some_die && !philo->elem->finished)
		printf("%llu %d is eating\n", get_time(philo, 1)
			- philo->elem->s_time, philo->id);
	else if (flag == 1 && !philo->elem->some_die
		&& !philo->elem->finished)
		printf("%llu %d is sleeping\n", get_time(philo, 0)
			- philo->elem->s_time, philo->id);
	else if (flag == 2 && !philo->elem->some_die
		&& !philo->elem->finished)
		printf("%llu %d is thinking\n", get_time(philo, 0)
			- philo->elem->s_time, philo->id);
	sem_post(philo->elem->writing);
}
