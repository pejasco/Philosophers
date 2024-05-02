/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:18 by siev              #+#    #+#             */
/*   Updated: 2024/05/02 22:17:07 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec / 1000));
}

//time_to_die = time_to_eat + time_to_sleep + 10
//time_to_die = time_to_eat * 2 + time_to_sleep + 10

/*
synchronization
1. odd sleep(time_to_eat /2)
2. odd start taking from rigt fork
3. all pilosopers take from right fork, except for the last one.


*/