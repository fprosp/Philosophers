/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:59:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 18:59:27 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(uint64_t time)
{
	uint64_t	tmp;

	tmp = ft_get_time();
	usleep(time * 1000 - 20000);
	while (ft_get_time() < tmp + time)
		continue ;
}