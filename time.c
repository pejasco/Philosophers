/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:45:18 by siev              #+#    #+#             */
/*   Updated: 2024/05/08 11:07:47 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long	time_since_epoch(void)
{
	struct timeval		time;
	long				milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000L + time.tv_usec / 1000L; 
	return (milliseconds);
}

long	get_time_since(long start_time)
{
	long	current_time;

	current_time = time_since_epoch();
	return (current_time - start_time);
}

void	fucking_sleep(long sleep_usec, t_feast_data *data)
{
	long	start_time;
	long	time_passed;
	long	diff;

	start_time = time_since_epoch();
	while (get_time_since(start_time) < sleep_usec)
	{
		if (sim_finished(data))
			break ;
		time_passed = get_time_since(start_time);
		diff = sleep_usec - time_passed;
		if (diff > 1e4)
			usleep(diff/ 2);
		else
			while (time_since_epoch() - start_time < sleep_usec)
				;
	}
}

