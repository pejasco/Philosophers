/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:22:43 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/10 11:57:42 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"
#include <limits.h>

int	check_1st_arg(char *arg)
{
	long	nbr;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit("Non-numeric input(s) found 😪");
		i++;
	}
	nbr = ft_atol(arg);
	if (nbr > 2147483647)
		error_exit("> than INT_MAX!!!! 😪");
	if (nbr <= 0)
		error_exit("0 or negtive no of philos WTF!!!! 😪");
	return (1);
}

int	check_args(char *arg)
{
	long			nbr;
	int				i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit("Non-numeric input(s) found 😪");
		i++;
	}
	nbr = ft_atol(arg);
	if (nbr > UINT_MAX)
		error_exit("Argument(s) over the uint max. (4294967295) 😪");
	return (1);
}

int	check_us_limit(long time)
{
	if (time > UINT_MAX)
		error_exit("Timestamp over the uint max. (4294967295) 😪");
	return (1);
}

void	time_limit_check(t_input *inputs)
{
	long	time_to_die_us;
	long	time_to_eat_us;
	long	time_to_sleep_us;

	time_to_die_us = (inputs->time_to_die_ms) * 1e3;
	time_to_eat_us = (inputs->time_to_eat_ms) * 1e3;
	time_to_sleep_us = (inputs->time_to_sleep_ms) * 1e3;
	check_us_limit(time_to_die_us);
	check_us_limit(time_to_eat_us);
	check_us_limit(time_to_sleep_us);
}

void	input_check(int ac, char **av, t_feast *feast)
{
	t_input		*inputs;

	inputs = &(feast->inputs);
	if (check_1st_arg(av[1]))
		inputs->no_of_philos = ft_atol(av[1]);
	if (check_args(av[2]))
		inputs->time_to_die_ms = ft_atol(av[2]);
	if (check_args(av[3]))
		inputs->time_to_eat_ms = ft_atol(av[3]);
	if (check_args(av[4]))
		inputs->time_to_sleep_ms = ft_atol(av[4]);
	if (ac == 6)
	{
		check_args(av[5]);
		inputs->no_of_meals = ft_atol(av[5]);
	}
	else
		inputs->no_of_meals = -1;
	time_limit_check(inputs);
	time_limit_check(inputs);
	time_limit_check(inputs);
}
