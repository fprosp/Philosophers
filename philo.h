/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:14:46 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/15 15:25:54 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h> 


typedef struct s_vars
{
	int argc;
	char **argv;
}	t_vars;

typedef struct s_philo
{
	int n_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_count;
}	t_philo;

int	num_check(t_vars *var, s_philo *philo)

#endif
