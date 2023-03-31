/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:24:12 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/11 12:53:25 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ull(char *str)
{
	long	n;

	n = ft_atoull(str);
	if (n > 4294967295)
		return (-1);
	return (0);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (i == 0 && str[i] == '+')
			i++;
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}

int	checks(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n < 1)
			return (error());
		if (n > 250 && i == 1)
			return (to_much_philo());
		if (n > 2147483647 || n < 0 || check_digits(argv[i]) == -1)
			return (error_args());
		if (check_ull(argv[i]) != 0)
			return (error_ui());
		i++;
	}
	return (0);
}
