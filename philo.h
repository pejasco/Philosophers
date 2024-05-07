/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:27:48 by siev              #+#    #+#             */
/*   Updated: 2024/05/07 18:38:45 by chuleung         ###   ########.fr       */
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

typedef enum e_hanlde_mod
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
	DETACH,
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

typedef enum e_full
{
	FULL,
	NOT_FULL,
} t_full;

typedef enum e_status
{
	EAT,
	THINK,
	SLEEP,
	TAKE_RF,
	TAKE_LF,
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

typedef	struct	s_feast_data
{
	long		start_time;
	bool		end_sim;
	bool		all_threads_ready;
	long		threads_running_nbr;
	bool		all_philo_alive;
	bool		all_full;
	bool		no_of_philos_parity;
	t_mutex		feast_data_mutex;
	t_mutex		msg_mutex;
	//t_mutex	msg_mutex;
} t_feast_data;

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
	t_life			life;
	t_full			full;
	t_status		status;
	pthread_t		thread_id;
	t_feast_data	*feast_data;
	t_mutex			philo_mutex;
}	t_philo;

typedef struct s_feast
{
	t_input			*inputs;
	t_philo			*philos;
	t_fork			*forks;
	t_feast_data	*feast_data;
	pthread_t		sexy_waitress;

}	t_feast;

//atoi
long		ft_atol(const char *arr);

//input
void		input_check(int ac, char **av, t_feast *feast);

//time
long		time_since_epoch(void);
long		get_time_since(long start_time);

//utili1
int			ft_isover_intmax(char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
void		error_exit(const char *error);

//utili2
t_parity	check_parity(int no_of_philos);
int			ft_strlen(char *str);

//feast
void	philos_taking_seat(t_feast *feast, t_philo *philos);

//mal_mtx
void	*malloc_hanlde(size_t bytes);
void	mutex_hanlde(t_mutex *mutex, t_op op);
void	thread_hanlde(pthread_t *thread, void *(*f)(void *),
		void *data, t_op op);

//write_n_read
void	write_bool(t_mutex *mutex, bool *dst, bool val);
bool	read_bool(t_mutex *mutex, bool *val);
void	write_long(t_mutex *mutex, long *dst, bool val);
long	read_long(t_mutex *mutex, long *val);



#endif
