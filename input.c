/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:22:43 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	//printf("%s\n", arg);
	nbr = ft_atol(arg);
	if (nbr <= 0)
		error_exit("0 or negtive no of philos WTF!!!! 😪");
	return (1);
}


int	check_args(char *arg)
{
	long		nbr;
	int			i;
	unsigned 	int y;

	i = 0;
	y = -1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit("Non-numeric input(s) found 😪");
		i++;
	}
	nbr = ft_atol(arg);
	if (nbr > UINT_MAX)
		error_exit("Over the uint max. (4294967295) 😪");
	return (1);
}

void input_check(int ac, char **av, t_input *inputs)
{	
	if (check_1st_arg(av[1]))
		inputs->no_of_philos = ft_atol(av[1]);
	if (check_args(av[2]))
		inputs->time_to_die = ft_atol(av[2]);
	if (check_args(av[3]))
		inputs->time_to_eat = ft_atol(av[3]);
	if (check_args(av[4]))
		inputs->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
	{
		check_args(av[5]);
		inputs->no_of_meals = ft_atol(av[5]);
	}
	else
		inputs->no_of_meals = 0;
}