/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:26 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/06 23:51:43 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdbool.h"

void	*actions_centre()
{
	printf("hahahaha\n");
}

int		create_threads_in_loop(int nbr_of_thread, pthread_t *threads)
{
	int			i;

	i = 0;
	while (i < nbr_of_thread)
	{
		if (pthread_create(threads + i, NULL, &actions_centre, NULL) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < nbr_of_thread)
	{
		if (pthread_join(threads + i, NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", i);
	}

}







int		thread_handle(int nbr_of_thread, t_feast *feast, pthread_mutex_t *mutex)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * (nbr_of_thread + 1));
	pthread_mutex_init(mutex, NULL);




	pthread_mutex_destroy(&mutex);
	
}

void	fork_init(t_feast *feast)
{
	long	no_of_philos;
	int		i;

	i = 0;
	no_of_philos = feast->inputs->no_of_philos;
	while (i < no_of_philos)
	{
		feast->forks[i].fork_id = i + 1;
		feast->forks[i].held_by_who = 0;
		pthread_mutex_init(&feast->forks[i].fork_mutex, NULL);
	}
}

void	init_fork_to_philo(t_feast *feast)
{
	long	no_of_philos;
	int		i;
	t_philo	*philos;

	i = 0;
	no_of_philos = feast->inputs->no_of_philos;
	philos = feast->philos;	
	while (i < no_of_philos)
	{
		if (i == 0)
			philos[i].right_fork = &feast->forks[no_of_philos - 1].fork_id;
		else
			philos[i].right_fork = &feast->forks[i - 1].fork_id;
		if (i == (no_of_philos -1))
			philos[i].left_fork = &feast->forks[0].fork_id;
		else
			philos[i].left_fork = &feast->forks[i + 1].fork_id;
		i++;
	}
}

void	philos_mutex_init(t_feast *feast, int i)
{
	t_philo *philo = &feast->philos[i];
	pthread_mutex_init(&(philo->last_meal_start_time_mutex), NULL);
	pthread_mutex_init(&(philo->eat_count_mutex), NULL);
	pthread_mutex_init(&(philo->parity_mutex), NULL);
	pthread_mutex_init(&(philo->life_mutex), NULL);
	pthread_mutex_init(&(philo->full_mutex), NULL);
	pthread_mutex_init(&(philo->status_mutex), NULL);
}


void	philos_init(t_feast *feast)
{
	long	no_of_philos;
	int		i;
	t_philo	*philos;
	long	*start_time;

	i = 0;
	start_time = &(feast->data->start_time);
	no_of_philos = feast->inputs->no_of_philos;
	philos = feast->philos;	
	init_fork_to_philo(feast);
	while (i < no_of_philos)
	{
		philos[i].philo_id = i + 1;
		feast->philos[i].last_meal_start_time = *start_time;
		feast->philos[i].eat_count = 0;
		feast->philos[i].parity = check_parity(philos[i].philo_id);
		feast->philos[i].life = ALIVE;
		feast->philos[i].full = FULL;
		feast->philos[i].status = START;
		philos_mutex_init(feast, i);
		i++;
	}
}


static void	philo_init(t_table *table)
{
`	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		safe_mutex_handle(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}















void	feast_init(t_feast *feast)
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
	feast->philos = malloc_handle(sizeof(t_philo) * no_of_philos);
	feast->forks = malloc_handle(sizeof(t_fork) * feast->inputs->no_of_philos);
	mutex_handle(&(feast_data->msg_mutex), INIT);
	mutex_handle(&(feast_data->feast_data_mutex), INIT);
	while (i < no_of_philos)
	{
		mutex_hanlde(&feast->forks[i], INIT);
		ta
		

		i++;
	}
	ph

}

