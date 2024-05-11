/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siev <siev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:18 by siev              #+#    #+#             */
/*   Updated: 2024/05/11 16:37:20 by siev             ###   ########.fr       */
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

void		sleep_well(long sleep_usec, t_feast *feast)
{
	long	start_time;
	long	time_passed;
	long	diff;

	start_time = time_since_epoch(MICROS);
	while (time_since_epoch(MICROS) - start_time < sleep_usec)
	{
		if (sim_ended(feast))
			break ;
		time_passed = time_since_epoch(MICROS) - start_time;
		diff = sleep_usec - time_passed;
		if (diff > 1e4)
			usleep(diff/ 2);
		else
			while (time_since_epoch(MICROS) - start_time < sleep_usec)
				;
	}
}
