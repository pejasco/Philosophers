/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:56 by siev              #+#    #+#             */
/*   Updated: 2024/05/03 18:47:44 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_feast			feast;
	pthread_mutex_t	mutex;

	if (ac == 5 || ac == 6)
	{
		input_check(ac, av, &feast);
		feast_setup(&feast, &mutex);
		return (0);
	}
	write(2, "Error - Invalid amount of arguments!!! 😪", 44);
	return (1);
}
