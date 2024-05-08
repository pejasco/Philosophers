/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   referee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:42 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/08 16:14:07 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

bool	if_philo_died(t_philo *philo, t_input *input)
{
	long	passed;
	long	time_to_die_ms;

	if (read_bool(&(philo->philo_mutex), &philo->full))
		return (false);
	passed = time_since_epoch() - read_long(&(philo->philo_mutex),
		&philo->last_meal_start_time);
	time_to_die_ms = input->time_to_die_ms;
	if (passed > time_to_die_ms)
		return (true);
	return (false);
}

void	waitress_partoling(void *info)
{
	int				i;
	t_feast_data	*data;

	data = (t_feast_data *)info;
	while (!all_threads_running(&(data->feast_data_mutex),
		&data->threads_running_nbr, data->input->no_of_philos))
		;
	while (!sim_ended(data))
	{
		i = -1;
		if (if_philo_died(data->philo + i, data->input))
		{
			write_bool(&data->feast_data_mutex, &data->end_sim, true);
			


		}
	}
	return (NULL);
}