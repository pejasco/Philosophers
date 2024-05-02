/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:56 by siev              #+#    #+#             */
/*   Updated: 2024/05/02 21:53:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_feast		feast;

	if (ac == 5 || ac == 6)
	{
		input_check(ac, av, &feast);
		setup_feast(&feast);
		printf("%ld\n", feast.inputs.no_of_philos);
		printf("%ld\n", feast.inputs.time_to_die);
		printf("%ld\n", feast.inputs.time_to_eat);
		printf("%ld\n", feast.inputs.time_to_sleep);
		printf("%ld\n", feast.inputs.no_of_meals);
		printf("\n");
		printf("%ld\n", feast.setup.no_of_philos);
		printf("%ld\n", feast.setup.time_to_die_us);
		printf("%ld\n", feast.setup.time_to_eat_us);
		printf("%ld\n", feast.setup.time_to_sleep_us);
		printf("%ld\n", feast.setup.no_of_meals);
		return (0);
	}
	write(2, "Error - Invalid amount of arguments!!! 😪", 44);
	return (1);
}
