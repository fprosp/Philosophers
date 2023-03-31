/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:37:23 by aliburdi          #+#    #+#             */
/*   Updated: 2023/03/31 16:33:53 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (ft_check_mutex(0, philo) != 0)
		ft_philo_msg(philo, philo->id, "has taken a fork 🍴");
	if (philo->everyone->n_ph == 1)
		return (1);
	pthread_mutex_lock(philo->right);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "has taken a fork 🍴");
	return (0);
}

void	 ft_action(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	if (ft_check_mutex(0, philo) != 0)
		ft_philo_msg(philo, philo->id, "is sleeping 💤");
	if (ft_check_mutex(0, philo) != 0)
		ft_sleep(philo->everyone->tt_sleep);
	if (ft_check_mutex(0, philo))
		ft_philo_msg(philo, philo->id, "is thinking 🤔");
}
