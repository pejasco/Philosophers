/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utili_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:56:55 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/09 22:09:04 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h> //printf
#include <stdlib.h> //exit failure

int		ft_isover_intmax(char *str)
{
	long	nbr;
	int		res;

	nbr = 0;
	res = 0;
	while (*str)
		nbr = (nbr * 10) + (*(str++) - '0');
	if (nbr > INT_MAX)
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

void	error_exit(const char *error)
{
	printf("🚨🚨 WARNING!!! %s 🚨🚨\n", error);
	exit(EXIT_FAILURE);
}

/*
int main()
{
	//char *hey = "truelove\n";

	//write(1, hey, ft_strlen(hey));
	//write(1, "Invalid amount of arguments\n", 28);
	//printf("%d\n", ft_strlen(hey));
	printf("%d\n", ft_isdigit('5'));
	return (0);
}
*/
