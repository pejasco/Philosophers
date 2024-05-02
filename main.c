/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:56 by siev              #+#    #+#             */
/*   Updated: 2024/05/02 16:14:34 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	t_input inputs;

	if (ac == 5 || ac == 6)
	{
		input_check(ac, av, &inputs);
		printf("%d\n", inputs.no_of_philos);
		printf("%ld\n", inputs.time_to_die);
		printf("%ld\n", inputs.time_to_eat);
		printf("%ld\n", inputs.time_to_sleep);
		printf("%ld\n", inputs.no_of_meals);
		return (0);
	}
	write(2, "Error - Invalid amount of arguments!!! 😪", 44);
	return (1);
}
