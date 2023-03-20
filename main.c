/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:06:27 by fprosper          #+#    #+#             */
/*   Updated: 2023/03/20 15:50:06 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int main(int argc, char **argv)
{
	t_vars var;

	var.argc = argc;
	var.argv = argv;
	if (check_get_init(&var) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	start(&var);
	return (EXIT_SUCCESS);
}
