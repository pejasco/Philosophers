/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:31:39 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/31 13:06:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*one_philio(t_feast *feast)
{
	printf("%-8s %s has taken a fork🍴🍴🍴\n",
		"0", "1");
	usleep(feast->inputs.time_to_die_ms * 1000);
	printf("%-8ld %s died!!!!!!🪦😵💀\n", feast->inputs.time_to_die_ms, "1");
	exit (1);
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
		eating(philo);
		write_msg(SLEEP, philo);
		sleep_well(philo->feast->inputs.time_to_sleep_ms * 1000, philo->feast);
		thinking(philo, false);
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
