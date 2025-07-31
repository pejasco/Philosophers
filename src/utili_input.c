/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:56:55 by chuleung          #+#    #+#             */
/*   Updated: 2025/07/31 13:52:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h> //printf
#include <stdlib.h>

int	ft_isover_intmax(char *str)
{
	long	nbr;

	nbr = 0;
	while (*str)
		nbr = (nbr * 10) + (*(str++) - '0');
	if (nbr > INT_MAX)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

void	error_exit(const char *error)
{
	printf("🚨🚨 WARNING!!! %s 🚨🚨\n", error);
	exit(EXIT_FAILURE);
}

