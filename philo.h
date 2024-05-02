/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:27:48 by siev              #+#    #+#             */
/*   Updated: 2024/05/02 22:02:51 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
//#include <stdio.h> //printf
//#include <stdlib.h> //malloc free
//#include <unistd.h> //write, usleep
//#include <sys/time.h> //gettimeofday
//#include <sys/types.h> uni_int64_t

# ifndef PHILO_MAX
#  define PHILO_MAX 200 
# endif

typedef pthread_mutex_t	t_mutex;

typedef struct s_input
{
	long	no_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	no_of_meals;
}	t_input;

typedef struct s_setup
{
	long	no_of_philos;
	long	time_to_die_us;
	long	time_to_eat_us;
	long	time_to_sleep_us;
	long	no_of_meals;
}	t_setup;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	t_fork		*left_fork;
	t_fork		*right_fork;		
}	t_philo;

typedef struct s_feast
{
	t_input		inputs;
	t_setup		setup;
	t_philo		philos;
}	t_feast;

//atoi
long	ft_atol(const char *arr);

//input
void	input_check(int ac, char **av, t_feast *feast);
void	setup_feast( t_feast *feast);

//utili1
int		ft_isover_intmax(char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	error_exit(const char *error);

//utili2
int		ft_strlen(char *str);

#endif