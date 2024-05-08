/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:14:32 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/08 23:16:23 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	incr_long(t_mutex *mutex, long *val)
{
	mutex_handle(mutex, LOCK);
	*val++;
	mutex_handle(mutex, UNLOCK);
}

void	all_threads_created(t_feast_data *feast_data)
{
	while(!read_bool(&feast_data->feast_data_mutex,
		&feast_data->all_threads_ready))
		;
}

bool	all_threads_running(t_mutex *mutex, long *total_running_threads,
		long *no_of_philos)
{
	bool	res;

	res = false;
	mutex_handle(mutex, LOCK);
	if (*total_running_threads == no_of_philos)
		res = true;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

bool	sim_ended(t_feast_data *data)
{
	return (get_bool(&data->feast_data_mutex, &(data->end_sim)));
}

void	avoid_having_two_stright_meal(t_feast_data *data, t_philo *philo)
{
	t_parity	parity;

	parity = data->no_of_philos_parity;
	if (parity == ODD)
	{
		if (philo->philo_id % 2)
			thinking(philo, true);
	}
	else if (parity == EVEN)
	{
		if (!(philo->philo_id % 2))
			fucking_sleep(4.2e4, data);
	}
}