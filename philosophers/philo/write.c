/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:13:43 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/11 11:47:17 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	num;
	int	cont;
	int	sig;

	num = 0;
	cont = 0;
	sig = 1;
	while (str[cont] == ' ' || (str[cont] > 8 && str[cont] < 14))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig *= -1;
		cont++;
	}
	if (!(str[cont] >= '0' && str[cont] <= '9'))
		return (0);
	while (str[cont] > 47 && str[cont] < 58)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	return (num * sig);
}

long long	ft_atoull(const char *str)
{
	int		num;
	long	cont;

	num = 0;
	cont = 0;
	while (str[cont] == ' ' || (str[cont] > 8 && str[cont] < 14))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
		return (0);
	if (!(str[cont] >= '0' && str[cont] <= '9'))
		return (0);
	while (str[cont] > 47 && str[cont] < 58)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	return (num);
}
