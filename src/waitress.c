/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:42 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/31 12:54:36 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

bool	if_philo_died(t_philo *philo, t_input *input)
{
	long	passed;
	long	time_to_die_ms;

	if (read_bool(&(philo->philo_mutex), &philo->full))
		return (false);
	passed = time_since_epoch(MILLIS) - read_long(&(philo->philo_mutex),
			&philo->last_meal_start_time);
	time_to_die_ms = input->time_to_die_ms;
	if (passed > time_to_die_ms)
		return (true);
	return (false);
}

void	*waitress_partoling(void *info)
{
	int				i;
	t_feast			*feast;

	feast = (t_feast *)info;
	while (!all_threads_running(&(feast->feast_mutex),
			&feast->threads_running_nbr, feast->inputs.no_of_philos))
		usleep(1e2);
	while (!sim_ended(feast))
	{
		i = 0;
		while (i < feast->inputs.no_of_philos && !sim_ended(feast))
		{
			if (if_philo_died(feast->philos + i, &feast->inputs))
			{
				write_bool(&feast->feast_mutex, &feast->end_sim, true);
				write_msg(DIE, feast->philos + i);
			}
			i++;
		}
		usleep(1e2);
	}
	return (NULL);
}

