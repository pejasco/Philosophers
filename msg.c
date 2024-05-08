/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:22:32 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/08 23:16:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	write_msg(t_status status, t_philo *philo, t_feast *feast)
{
	long	time_passed;

	time_passed = time_since_epoch - feast->feast_data->start_time;
	if (read_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handle(&feast->feast_data->msg_mutex, LOCK);
	if ((status ==  TAKE_1st_Fork|| status == TAKE_2nd_Fork)
		&& !sim_ended(feast->feast_data))
		printf("%-8ld %d has taken a fork🍴🍴🍴 \n",
			time_passed, philo->philo_id);
	else if (status == EAT && !sim_ended(feast->feast_data))
		printf("%-8ld %d is eating🍝😋🥘\n", time_passed, philo->philo_id);
	else if (status == SLEEP && !sim_ended(feast->feast_data))
		printf("%-8ld %d is sleeping😪💤😴\n", time_passed, philo->philo_id);
	else if (status == THINK && !sim_ended(feast->feast_data))
		printf("%-8ld %d is thinking🤔🤔🤔\n", time_passed, philo->philo_id);
	else if (status == DIE && !sim_ended(feast->feast_data))
		printf("%-8ld %d DIE!!!!!!🪦😵💀\n", time_passed, philo->philo_id);
	mutex_handle(&feast->feast_data->msg_mutex);
}
