/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:26 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/08 16:05:46 by chuleung         ###   ########.fr       */
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
		philo->feast_data = &(feast->feast_data);
		whose_forks(philo, feast->forks, i);
		i++;
	}
}

void	feast_setup(t_feast *feast)
{
	t_feast_data	*feast_data;
	long			no_of_philos;
	int				i;

	i = 0;
	no_of_philos = feast->inputs->no_of_philos;
	feast_data = &(feast->feast_data);
	feast_data->end_sim = false;
	feast_data->all_threads_ready = false;
	feast_data->threads_running_nbr = 0;
	feast_data->no_of_philos_parity = check_parity(no_of_philos);
	feast->philos = malloc_handle(sizeof(t_philo) * no_of_philos);
	feast->forks = malloc_handle(sizeof(t_fork) * no_of_philos);
	feast_data->input = &feast->inputs;
	feast_data->philo = &feast->philos;
	mutex_handle(&(feast_data->msg_mutex), INIT);
	mutex_handle(&(feast_data->feast_data_mutex), INIT);
	while (i < no_of_philos)
	{
		mutex_hanlde(&feast->forks[i].fork_mutex, INIT);
		feast->forks[i].fork_id = i;
	}
	philos_taking_seat(feast ,&feast->philos);
}
