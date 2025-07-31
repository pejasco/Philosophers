/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:46:49 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/02 15:55:48 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *arr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(arr[i]))
		i++;
	if (arr[i] == '-' || arr[i] == '+')
	{
		if (arr[i] == '-')
			sign *= -1;
		i++;
	}
	i = 0;
	while (ft_isdigit(arr[i]))
	{
		res = res * 10 + (arr[i] - '0');
		i++;
	}
	return (res * sign);
}
