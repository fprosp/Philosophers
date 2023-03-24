/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:59:09 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/24 17:49:51 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void routine(void *philo_ptr)
{
	t_philo *philo;

	philo = (t_philo*)philo_ptr;
	if (philo->philo_id % 2 == 0)
		ft_sleep(60);

	
}

