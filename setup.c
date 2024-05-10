/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:26 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/10 01:45:27 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdbool.h"

void	whose_forks(t_philo *philo, t_feast *feast, long philo_post)
{
	long	no_of_philos;
	t_fork	*forks;

	no_of_philos = feast->inputs->no_of_philos;  
	forks = feast->forks;
	if (philo->philo_id % 2 == 0)
	{
		philo->first_fork = &forks[philo_post];
		philo->second_fork = &forks[(philo_post + 1) % no_of_philos];
	}
	else
	{
		philo->first_fork = &forks[(philo_post + 1) % no_of_philos];
		philo->second_fork = &forks[philo_post];
	}
}

void	philos_taking_seat(t_feast *feast, t_philo *philos)
{
	long		i;
	long		no_of_philos;
	t_philo		*philo;

	i = 0;
	no_of_philos = feast->inputs->no_of_philos;
	while (i < no_of_philos)
	{
		philo = philos + i;
		philo->philo_id = i + 1;
		philo->full = false;
		philo->eat_count = 0;
		mutex_handle(&philo->philo_mutex, INIT);
		philo->feast = feast;
		whose_forks(philo, feast, i);
		i++;
	}
}

void	feast_setup(t_feast *feast)
{
	long			no_of_philos;
	int				i;

	i = 0;
	no_of_philos = feast->inputs->no_of_philos;
	feast->end_sim = false;
	feast->all_threads_ready = false;
	feast->threads_running_nbr = 0;
	feast->no_of_philos_parity = check_parity(no_of_philos);
	feast->philos = malloc_handle(sizeof(t_philo) * no_of_philos);
	feast->forks = malloc_handle(sizeof(t_fork) * no_of_philos);
	mutex_handle(&(feast->msg_mutex), INIT);
	mutex_handle(&(feast->feast_mutex), INIT);
	while (i < no_of_philos)
	{
		mutex_handle(&feast->forks[i].fork_mutex, INIT);
		feast->forks[i].fork_id = i;
	}
	philos_taking_seat(feast, feast->philos);
}
