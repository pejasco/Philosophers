/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:14:32 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/10 15:19:08 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	incr_long(t_mutex *mutex, long *val)
{
	mutex_handle(mutex, LOCK);
	(*val)++;
	mutex_handle(mutex, UNLOCK);
}

void	all_threads_created(t_feast *feast)
{
	while(!read_bool(&feast->feast_mutex,
		&feast->all_threads_ready))
		;
}

bool	all_threads_running(t_mutex *mutex, long *total_running_threads,
		long no_of_philos)
{
	bool	res;

	res = false;
	mutex_handle(mutex, LOCK);
	if (*total_running_threads == no_of_philos)
		res = true;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

bool	sim_ended(t_feast *feast)
{
	return (read_bool(&feast->feast_mutex, &(feast->end_sim)));
}

void	avoid_having_two_stright_meal(t_philo *philo)
{
	if (philo->feast->inputs.no_of_philos % 2 == 0)
	{
		if (philo->philo_id % 2 == 0)
			sleep_well(3e4, philo->feast);
	}
	else
	{
		if (philo->philo_id % 2)
			fucking_think(philo, true);
	}
}
