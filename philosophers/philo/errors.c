/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:22:18 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 12:14:04 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(void)
{
	ft_putstr("Usage: ./philo number_of_philosophers ");
	ft_putstr("time_to_die time_to_eat time_to_sleep ");
	ft_putstr("[number_of_times_each_philosophers_must_eat]\n");
	return (-1);
}

int	to_much_philo(void)
{
	ft_putstr("There are to many philosophers!\n");
	return (-1);
}

int	error_args(void)
{
	ft_putstr("Non-positive integers parameters were passed to executable.\n");
	return (-1);
}

int	error_ui(void)
{
	ft_putstr("Arguments must be of unsigned integer type.\n");
	return (-1);
}

int	error(void)
{
	ft_putstr("ERROR\n");
	return (-1);
}
