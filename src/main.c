/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:56 by siev              #+#    #+#             */
/*   Updated: 2024/05/12 20:18:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_feast			feast;

	if (ac != 5 && ac != 6)
	{
		write(2, "Error - Invalid amount of arguments!!! 😪", 44);
		return (1);
	}
	input_check(ac, av, &feast);
	feast_setup(&feast);
	feast_start(&feast);
	super_clean(&feast);
	return (0);
}
