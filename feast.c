/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:26 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/04 18:28:43 by chuleung         ###   ########.fr       */
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

int		feast_init(t_feast *feast, pthread_mutex_t	*mutex)
{
	int	no_of_philos;
	int	i;

	no_of_philos = feast->inputs->no_of_philos;
	feast->data->start_time = time_since_epoch;
	feast->philos = malloc(sizeof(t_philo) * no_of_philos);
	feast->forks = malloc(sizeof(t_fork) * feast->inputs->no_of_philos);
	feast->threads = malloc(sizeof(pthread_t) * (no_of_philos + 1));
	i = 0;
	while (i < no_of_philos)
	{


		i++;
	}






}

