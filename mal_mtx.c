/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mal_mtx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:03:27 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/06 15:58:03 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_hanlde(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Error with the malloc");
	return (ret);
}

void	mutex_hanlde(t_mutex *mutex, t_op op)
{
	if (op == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (op == LOCK)
		pthread_mutex_lock(mutex);
	else if (op == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (op == UNLOCK)
		pthread_mutex_destory(mutex);
}

void	thread_hanlde(pthread_t *thread, void *(*f)(void *),
	void *data, t_op op)
{	
	if (op == INIT)
		pthread_create(thread, NULL, f, data);
	else if (op == LOCK)
		pthread_join(*thread, NULL);
	else if (op == UNLOCK)
		pthread_detach(*thread);
}
