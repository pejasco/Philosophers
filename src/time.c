/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:18 by siev              #+#    #+#             */
/*   Updated: 2025/07/31 13:52:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long	time_since_epoch(t_time format)
{
	struct timeval		time;
	long				res;

	res = -1;
	gettimeofday(&time, NULL);
	if (format == MILLIS)
		res = time.tv_sec * 1000L + time.tv_usec / 1000L;
	else if (format == MICROS)
		res = time.tv_sec * 1000000L + time.tv_usec;
	return (res);
}

long	get_time_since(long start_time, t_time format)
{
	long	current_time;

	current_time = time_since_epoch(format);
	return (current_time - start_time);
}

void sleep_well(long sleep_usec, t_feast *feast)
{
    long start_time = time_since_epoch(MICROS);
    while (time_since_epoch(MICROS) - start_time < sleep_usec)
    {
        if (sim_ended(feast))
            break;
        usleep(100);
    }
}

