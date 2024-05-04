/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:27:48 by siev              #+#    #+#             */
/*   Updated: 2024/05/04 17:50:09 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>

//#include <stdio.h> //printf
//#include <stdlib.h> //malloc free
//#include <unistd.h> //write, usleep
//#include <sys/time.h> //gettimeofday
//#include <sys/types.h> uni_int64_t

//Each philsopher should be a thread
//protext the forks state with a mutex for each of them
//

typedef pthread_mutex_t	t_mutex;

typedef enum e_parity
{
	ODD,
	EVEN,
} t_parity;

typedef enum e_life
{
	ALIVE,
	DEAD,
} t_life;

typedef enum e_status
{
	EAT,
	THINK,
	SLEEP,
} t_status;

typedef struct s_input
{
	long	no_of_philos;
	long	time_to_die_ms;
	long	time_to_eat_ms;
	long	time_to_sleep_ms;
	long	no_of_meals;
}	t_input;

typedef	struct	s_data
{
	long	start_time;
	bool	all_philo_alive;
	t_mutex	all_philo_alive_mutex;
	bool	all_full;
	t_mutex	all_full_mutex;
	bool	no_of_philos_is_even;
	//t_mutex	msg_mutex;
} t_data;

typedef struct s_fork
{
	long		fork_id;
	long		held_by_who;
	t_mutex		fork_mutex;
}	t_fork;

typedef struct s_philo
{
	long		id;
	t_fork		*left_fork;
	t_fork		*right_fork;
	long		last_meal_start_time;
	t_mutex		last_meal_start_time_mutex;
	long		eat_count;
	t_mutex		eat_count_mutex;
	t_parity	parity;
	t_mutex		parity_mutex;
	t_life		life;
	t_mutex		life_mutex;
	t_status	status;
}	t_philo;

typedef struct s_feast
{
	t_input		*inputs;
	t_philo		*philos;
	t_fork		*forks;
	t_data		*data;
	pthread_t	threads;
}	t_feast;

//atoi
long	ft_atol(const char *arr);

//input
void	input_check(int ac, char **av, t_feast *feast);

//time
long	time_since_epoch(void);
long	get_time_since(long start_time);

//utili1
int		ft_isover_intmax(char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	error_exit(const char *error);

//utili2
int		ft_strlen(char *str);

//feast
int		feast_init(t_feast *feast, pthread_mutex_t	*mutex);

#endif
