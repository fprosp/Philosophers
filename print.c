/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:44:04 by fprosper          #+#    #+#             */
/*   Updated: 2023/04/11 18:21:40 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info(t_philo *ph, int id, char *str)
{
	pthread_mutex_lock(&ph->vars->lock);
	printf("%llu", get_ms_time() - ph->vars->start_time);
	printf(" %d %s\n", id, str);
	pthread_mutex_unlock(&ph->vars->lock);
}

void	print_death(t_philo *i_philo, int id, char *str)
{
	pthread_mutex_lock(&i_philo->vars->lock);
	printf("%llu", get_ms_time() - i_philo->vars->start_time);
	printf(" %d %s\n", id, str);
}
