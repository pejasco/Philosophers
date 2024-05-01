/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:59:14 by chuleung          #+#    #+#             */
/*   Updated: 2024/05/01 22:07:24 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> //exit failure

int ft_strlen(char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (-1);
	while (str[len])
		len++;
	return (len);
}

