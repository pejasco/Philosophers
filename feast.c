/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siev <siev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:31:39 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/11 22:51:27 by siev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philio(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	all_threads_created(philo->feast);
	write_long(&philo->philo_mutex, &philo->last_meal_start_time,
		time_since_epoch(MILLIS));
	incr_long(&philo->feast->feast_mutex,
		&philo->feast->threads_running_nbr);
	write_msg(TAKE_1ST_FORK, philo);
	while (!sim_ended(philo->feast))
		sleep_well(200, philo->feast);
	return (NULL);
}

void	*feast_sim(void *info)
{
	t_philo		*philo;

	philo = (t_philo *)info;
	all_threads_created(philo->feast);
	write_long(&philo->philo_mutex, &philo->last_meal_start_time,
		time_since_epoch(MILLIS));
	incr_long(&philo->feast->feast_mutex,
		&philo->feast->threads_running_nbr);
	avoid_having_two_stright_meal(philo);
	while (!sim_ended(philo->feast))
	{
		if (read_bool(&philo->philo_mutex, &philo->full))
			break ;
		fucking_eat(philo);
		write_msg(SLEEP, philo);
		sleep_well(philo->feast->inputs.time_to_sleep_ms * 1000, philo->feast);
		fucking_think(philo, false);
	}
	return (NULL);
}

void	how_many_threads_needed(t_feast *feast)
{
	long	no_of_philos;
	int		i;

	i = 0;
	no_of_philos = feast->inputs.no_of_philos;
	if (feast->inputs.no_of_meals == 0)
		return ;
	else if (no_of_philos == 1)
		thread_handle(&feast->philos[0].thread_id, one_philio,
			&feast->philos[0], CREATE);
	else
	{
		while (i < no_of_philos)
		{
			thread_handle(&feast->philos[i].thread_id, feast_sim,
				&feast->philos[i], CREATE);
			i++;
		}
	}
}

void	feast_start(t_feast *feast)
{
	long	i;

	i = 0;
	how_many_threads_needed(feast);
	thread_handle(&feast->hot_waitress, waitress_partoling, feast, CREATE);
	feast->start_time = time_since_epoch(MILLIS);
	write_bool(&feast->feast_mutex, &feast->all_threads_ready, true);
	while (i < feast->inputs.no_of_philos)
	{
		thread_handle(&feast->philos[i].thread_id, NULL, NULL, JOIN);
		i++;		
	}
	write_bool(&feast->feast_mutex, &feast->end_sim, true);
	thread_handle(&feast->hot_waitress, NULL, NULL, JOIN);
}
