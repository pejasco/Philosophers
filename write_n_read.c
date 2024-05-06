/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_n_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:30:34 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/06 19:45:35 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	write_bool(t_mutex *mutex, bool *dst, bool val)
{
	mutex_handle(mutex, LOCK);
	*dst = val;
	mutex_handle (mutex, UNLOCK);
}

bool	read_bool(t_mutex *mutex, bool *val)
{
	bool res;

	mutex_handle(mutex, LOCK);
	res = *val;
	mutex_handle(mutex, UNLOCK);
	return (res);
}

void	write_long(t_mutex *mutex, long *dst, bool val)
{
	mutex_handle(mutex, LOCK);
	*dst = val;
	mutex_handle (mutex, UNLOCK);
}

long	read_long(t_mutex *mutex, long *val)
{
	long res;

	mutex_handle(mutex, LOCK);
	res = *val;
	mutex_handle(mutex, UNLOCK);
	return (res);
}
