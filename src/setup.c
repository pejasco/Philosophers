/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:26 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/12 23:12:27 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdbool.h"

void	whose_forks(t_philo *philo, t_fork *forks, long philo_post)
{
	long	no_of_philos;

	no_of_philos = philo->feast->inputs.no_of_philos;
	philo->first_fork = &forks[(philo_post + 1) % no_of_philos];
	philo->second_fork = &forks[philo_post];
	if (philo->philo_id % 2 == 0)
	{
		philo->first_fork = &forks[philo_post];
		philo->second_fork = &forks[(philo_post + 1) % no_of_philos];
	}
}

void	philos_taking_seat(t_feast *feast)
{
	long		i;
	t_philo		*philo;

	i = 0;
	while (i < (feast->inputs.no_of_philos))
	{
		philo = feast->philos + i;
		philo->philo_id = i + 1;
		philo->full = false;
		philo->eat_count = 0;
		philo->parity = check_parity(philo->philo_id);
		mutex_handle(&philo->philo_mutex, INIT);
		philo->feast = feast;
		whose_forks(philo, feast->forks, i);
		i++;
	}
}

void	feast_setup(t_feast *feast)
{
	long			no_of_philos;
	int				i;

	i = 0;
	if (feast->inputs.no_of_philos == 1)
		one_philio(feast);
	no_of_philos = feast->inputs.no_of_philos;
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
		i++;
	}
	philos_taking_seat(feast);
}
