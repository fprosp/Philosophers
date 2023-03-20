/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:34:23 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:33 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	space_check(const char *str, int i)
{
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v' \
		    || *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
		i++;
	return (i);
}

int	ascii_to_int(const char *str)
{
	int	result;
	int	i;
	int	segno;

	i = 0;
	segno = 1;
	result = 0;
	i = space_check(str, i);
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