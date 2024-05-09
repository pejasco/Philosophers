/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:22:32 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/09 18:30:41 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	write_msg(t_status status, t_philo *philo)
{
	long	time_passed;

	time_passed = time_since_epoch - philo->feast->start_time;
	if (read_bool(&philo->philo_mutex, &philo->full))
		return ;
	mutex_handle(&philo->feast->msg_mutex, LOCK);
	if ((status ==  TAKE_1ST_FORK|| status == TAKE_2ND_FORK)
		&& !sim_ended(philo->feast))
		printf("%-8ld %d has taken a fork🍴🍴🍴 \n",
			time_passed, philo->philo_id);
	else if (status == EAT && !sim_ended(philo->feast))
		printf("%-8ld %d is eating🍝😋🥘\n", time_passed, philo->philo_id);
	else if (status == SLEEP && !sim_ended(philo->feast))
		printf("%-8ld %d is sleeping😪💤😴\n", time_passed, philo->philo_id);
	else if (status == THINK && !sim_ended(philo->feast))
		printf("%-8ld %d is thinking🤔🤔🤔\n", time_passed, philo->philo_id);
	else if (status == DIE && !sim_ended(philo->feast))
		printf("%-8ld %d died!!!!!!🪦😵💀\n", time_passed, philo->philo_id);
	mutex_handle(&philo->feast->msg_mutex, UNLOCK);
}
