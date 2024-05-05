/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:59:14 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/05 00:37:22 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h> //printf
#include <stdlib.h> //exit failure
#include <stdbool.h> //bool

t_parity	check_parity(int philo_id)
{
	if (no_of_philos % 2 == 0)
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
