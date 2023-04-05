/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:18:58 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/05 13:52:29 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	edit_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	edit_sleep(uint64_t time)
{
	uint64_t	tmp;

	tmp = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < tmp + time)
		continue ;
}

