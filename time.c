/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siev <siev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:18 by siev              #+#    #+#             */
/*   Updated: 2024/04/30 19:11:21 by siev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time(void)
{
	struct timeval	tv;
// 
	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

//time_to_die = time_to_eat + time_to_sleep + 10
//time_to_die = time_to_eat * 2 + time_to_sleep + 10

/*
synchronization
1. odd sleep(time_to_eat /2)
2. odd start taking from rigt fork
3. all pilosopers take from right fork, except for the last one.


*/