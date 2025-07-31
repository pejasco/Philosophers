/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:26:40 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/31 13:06:02 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, bool pre_sim)
{
	long	time_to_eat_ms;
	long	time_to_sleep_ms;
	long	time_to_think_ms;
	long	no_of_philos;

	no_of_philos = philo->feast->inputs.no_of_philos;
	write_msg(THINK, philo);
	if (!pre_sim)
		write_msg(THINK, philo);
	if (no_of_philos % 2 == 0)
		return ;
	time_to_eat_ms = philo->feast->inputs.time_to_eat_ms;
	time_to_sleep_ms = philo->feast->inputs.time_to_sleep_ms;
	time_to_think_ms = time_to_eat_ms * 2 - time_to_sleep_ms;
	if (time_to_think_ms < 0)
		time_to_think_ms = 0;
	sleep_well(time_to_think_ms * 1000 * 0.38, philo->feast);
}

void	eating(t_philo *philo)
{
	mutex_handle(&philo->first_fork->fork_mutex, LOCK);
	write_msg(TAKE_1ST_FORK, philo);
	mutex_handle(&philo->second_fork->fork_mutex, LOCK);
	write_msg(TAKE_2ND_FORK, philo);
	write_long(&philo->philo_mutex, &philo->last_meal_start_time,
		time_since_epoch(MILLIS));
	philo->eat_count++;
	write_msg(EAT, philo);
	sleep_well(philo->feast->inputs.time_to_eat_ms * 1000, philo->feast);
	if (philo->feast->inputs.no_of_meals > 0
		&& philo->eat_count == philo->feast->inputs.no_of_meals)
		write_bool(&philo->philo_mutex, &philo->full, true);
	mutex_handle(&philo->first_fork->fork_mutex, UNLOCK);
	mutex_handle(&philo->second_fork->fork_mutex, UNLOCK);
}
