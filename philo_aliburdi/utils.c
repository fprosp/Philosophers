/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:35:47 by aliburdi          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:18 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *str)
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

void	ft_sleep(uint64_t time)
{
	uint64_t	tmp;

	tmp = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < tmp + time)
		continue ;
}

void	ft_philo_msg(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->everyone->lock);
	printf("%llu", ft_get_time() - ph->everyone->start_time);
	printf(" %d %s\n", id, str);
	pthread_mutex_unlock(&ph->everyone->lock);
}

uint64_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}
