/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:22:43 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/01 23:56:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	check_1st_arg(char *arg)
{
	int		nbr;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit("Non-numeric input(s) found 😪");
		i++;
	}
	nbr = ft_atoi(arg);
	if (nbr <= 0)
		error_exit("0 or negtive no of philos WTF!!!! 😪");
	return (0);
}


int	check_args(char *arg)
{
	int		nbr;
	int		i;

	unsigned int y;

	i = 0;
	y = -1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit("Non-numeric input(s) found 😪");
		i++;
	}
	nbr = ft_atoi(arg);
	if (nbr > UINT_MAX)
		error_exit("Over the int max. (2147483647) 😪");
	return (0);
}

void input_check(int ac, char **av, t_input *inputs)
{	
	if (!check_1st_arg(av[1]))
		inputs->no_of_philos = ft_atoi(av[1]);
	if (!check_args(av[2]))
		inputs->time_to_die = ft_atoi(av[2]);
	if (!check_args(av[3]))
		inputs->time_to_eat = ft_atoi(av[3]);
	if (!check_args(av[4]))
		inputs->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6 && check_args(av[5]))
		inputs->no_of_meals = ft_atoi(av[5]);
}