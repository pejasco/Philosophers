/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:22:32 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/12 20:17:58 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	write_msg(t_status status, t_philo *philo)
{
	long	time_passed;

	time_passed = time_since_epoch(MILLIS) - philo->feast->start_time;
	if (read_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handle(&philo->feast->msg_mutex, LOCK);
	if ((status == TAKE_1ST_FORK || status == TAKE_2ND_FORK)
		&& !sim_ended(philo->feast))
		printf("%-8ld %ld has taken a fork🍴🍴🍴\n",
			time_passed, philo->philo_id);
	else if (status == EAT && !sim_ended(philo->feast))
		printf("%-8ld %ld is eating🍝😋🥘\n", time_passed, philo->philo_id);
	else if (status == SLEEP && !sim_ended(philo->feast))
		printf("%-8ld %ld is sleeping😪💤😴\n", time_passed, philo->philo_id);
	else if (status == THINK && !sim_ended(philo->feast))
		printf("%-8ld %ld is thinking🤔🤔🤔\n", time_passed, philo->philo_id);
	else if (status == DIE)
		printf("%-8ld %ld died!!!!!!🪦😵💀\n", time_passed, philo->philo_id);
	mutex_handle(&philo->feast->msg_mutex, UNLOCK);
}
