/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:30:26 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/15 16:08:22 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	controllo_spazi(const char *str, int i)
{
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v' \
		    || *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	segno;

	i = 0;
	segno = 1;
	result = 0;
	i = controllo_spazi(str, i);
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			segno = -1;
		i++;
	}
	while (*(str + i) <= '9' && *(str + i) >= '0')
	{
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	return (result * segno);
}

int var_assign(t_vars *var, t_philo *philo)
{
    philo->n_philo = ft_atoi(var->argv[1]);
    if (philo->n_philo > 200 && philo->n_philo <= 0)
        return (1);
    philo->time_to_die = ft_atoi(var->argv[2]);
    philo->time_to_eat = ft_atoi(var->argv[3]);
    philo->time_to_sleep = ft_atoi(var->argv[4]);
    if (philo->time_to_die < 0 || philo->time_to_eat < 0 || philo->time_to_sleep < 0)
        return (1);
    if (var->argv[5])
        philo->eat_count = ft_atoi(var->argv[5]);
        if (philo->eat_count < 7)
            return (1);
	else
		philo->eat_count = -1;
    return (0);
}

int	num_check(t_vars *var, t_philo *philo)
{
	int i;
	int	j;

    if (var->argc < 5 || var->argc > 6)
		return (1);
	i = 1;
	while (i <= var->argc)
	{
		j = 0;
		while (var->argv[i][j] != '\0')
		{
			if (ft_isdigit((int)var->argv[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
    if (var_assig(var, philo) == 1)
        return (1);
	return (0);
}