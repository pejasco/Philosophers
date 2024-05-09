/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:59:14 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/09 22:09:10 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h> //printf
#include <stdlib.h> //exit failure
#include <stdbool.h> //bool

t_parity	check_parity(int nbr)
{
	if (nbr % 2 == 0)
		return (EVEN);
	else
		return (ODD);	
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (-1);
	while (str[len])
		len++;
	return (len);
}

void	clean_all(t_feast *feast)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < feast->inputs->no_of_philos)
	{
		philo = feast->philos + i;
		mutex_handle(&philo->philo_mutex, DESTROY);
		i++;
	}
	mutex_handle(&feast->msg_mutex, DESTROY);
	mutex_handle(&feast->msg_mutex, DESTROY);
	free(feast->forks);
	free(feast->philos);
}
