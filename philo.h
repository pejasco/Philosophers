/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siev <siev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:27:48 by siev              #+#    #+#             */
/*   Updated: 2024/05/11 16:36:33 by siev             ###   ########.fr       */
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
typedef struct s_feast t_feast;

typedef enum e_handle_mod
{
	WRITE,
	READ,
} t_handle_mod;

typedef	enum e_op
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	CREATE,
	JOIN,
} t_op;

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

typedef enum e_time
{
	MILLIS,
	MICROS,
} t_time;

typedef enum e_status
{
	EAT,
	THINK,
	SLEEP,
	TAKE_1ST_FORK,
	TAKE_2ND_FORK,
	DIE,
} t_status;

typedef struct s_input
{
	long	no_of_philos;
	long	time_to_die_ms;
	long	time_to_eat_ms;
	long	time_to_sleep_ms;
	long	no_of_meals;
}	t_input;


/*
typedef	struct	s_feast_data
{
	long		start_time;
	bool		end_sim;
	bool		all_threads_ready;
	long		threads_running_nbr;
	bool		all_philo_alive;
	//bool		all_full;
	bool		no_of_philos_parity;
	t_input		*input;
	t_philo		*philo;
	t_mutex		feast_data_mutex;
	t_mutex		msg_mutex;
} t_feast_data;
*/

typedef struct s_fork
{
	long		fork_id;
	t_mutex		fork_mutex;
}	t_fork;

typedef struct s_philo
{
	long			philo_id;
	t_fork			*first_fork;
	t_fork			*second_fork;
	long			last_meal_start_time;
	long			eat_count;
	t_parity		parity;
	bool			full;
	pthread_t		thread_id;
	t_feast			*feast;
	t_mutex			philo_mutex;
}	t_philo;

typedef struct s_feast
{
	t_input			inputs;
	long			start_time;
	bool			end_sim;
	bool			all_threads_ready;
	long			threads_running_nbr;
	t_parity		no_of_philos_parity;
	pthread_t		hot_waitress;
	t_philo			*philos;
	t_fork			*forks;
	t_mutex			feast_mutex;
	t_mutex			msg_mutex;
}	t_feast;

//atol
long		ft_atol(const char *arr);

//action
void		fucking_think(t_philo *philo, bool pre_sim);
void		fucking_eat(t_philo *philo);

//feast
void		*one_philio(void *arg);
void		*feast_sim(void *info);
void		how_many_threads_needed(t_feast *feast);
void		feast_start(t_feast *feast);

//input
void		input_check(int ac, char **av, t_feast *feast);

//mal_mtx
void		*malloc_handle(size_t bytes);
void		mutex_handle(t_mutex *mutex, t_op op);
void		thread_handle(pthread_t *thread, void *(*f)(void *), void *feast, t_op op);

//msg
void		write_msg(t_status status, t_philo *philo);

//setup
void		philos_taking_seat(t_feast *feast);
void		whose_forks(t_philo *philo, t_fork *forks, long philo_post);
void		feast_setup(t_feast *feast);

//sync
void		incr_long(t_mutex *mutex, long *val);
void		all_threads_created(t_feast *feast);
bool		all_threads_running(t_mutex *mutex, long *total_running_threads,
				long no_of_philos);
bool		sim_ended(t_feast *feast);
void		avoid_having_two_stright_meal(t_philo *philo);

//time
long		time_since_epoch(t_time format);
//long		get_time_since(long start_time, t_time format);
void		sleep_well(long sleep_usec, t_feast *feast);

//utili_input
int			ft_isover_intmax(char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
void		error_exit(const char *error);

//utili_others
t_parity	check_parity(long nbr);
int			ft_strlen(char *str);
void		super_clean(t_feast *feast);

//waitress
bool		if_philo_died(t_philo *philo, t_input *input);
void		*waitress_partoling(void *info);

//write_n_read
void		write_bool(t_mutex *mutex, bool *dst, bool val);
bool		read_bool(t_mutex *mutex, bool *val);
void		write_long(t_mutex *mutex, long *dst, long val);
long		read_long(t_mutex *mutex, long *val);

#endif




/*
typedef	struct	s_feast_data
{
	long		start_time;
	bool		end_sim;
	bool		all_threads_ready;
	long		threads_running_nbr;
	bool		all_philo_alive;
	//bool		all_full;
	bool		no_of_philos_parity;
	t_input		*input;
	t_philo		*philo;
	t_mutex		feast_data_mutex;
	t_mutex		msg_mutex;
} t_feast_data;
*/