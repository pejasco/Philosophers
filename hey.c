Looking at the selected code, there are a few areas that could potentially be optimized:

Busy waiting: In the all_threads_created function, you're using a busy wait loop to check if all threads are ready. This can be inefficient as it consumes CPU cycles while waiting. Consider using a condition variable or a semaphore to block the thread until all threads are ready.

Mutex locking: In the all_threads_running function, you're locking the mutex even when it's not necessary. If you first check if (*total_running_threads != no_of_philos) before locking the mutex, you can avoid unnecessary locking and unlocking, which are relatively expensive operations.

Avoid unnecessary computation: In the avoid_having_two_stright_meal function, you're checking if (philo->feast->inputs.no_of_philos % 2 == 0) for each philosopher. Since the number of philosophers doesn't change, you could calculate this once and store the result, rather than calculating it for each philosopher.

Here's how you might modify your code to incorporate these suggestions:

void	all_threads_created(t_feast *feast)
{
    pthread_mutex_lock(&feast->feast_mutex);
    while (!feast->all_threads_ready)
        pthread_cond_wait(&feast->all_threads_ready_cond, &feast->feast_mutex);
    pthread_mutex_unlock(&feast->feast_mutex);
}

bool	all_threads_running(t_mutex *mutex, long *total_running_threads,
        long no_of_philos)
{
    if (*total_running_threads != no_of_philos)
    {
        mutex_handle(mutex, LOCK);
        bool res = (*total_running_threads == no_of_philos);
        mutex_handle(mutex, UNLOCK);
        return res;
    }
    return false;
}

void	avoid_having_two_stright_meal(t_philo *philo)
{
    static bool is_even = false;
    static bool is_even_calculated = false;

    if (!is_even_calculated)
    {
        is_even = (philo->feast->inputs.no_of_philos % 2 == 0);
        is_even_calculated = true;
    }

    if (is_even)
    {
        if (philo->parity == EVEN)
            sleep_well(3e4, philo->feast);
    }
    else
    {
        if (philo->parity == ODD)
            fucking_think(philo, true);
    }
}
Looking at the selected code, there are a few areas that could potentially be optimized:

1. **Busy waiting**: In the `all_threads_created` function, you're using a busy wait loop to check if all threads are ready. This can be inefficient as it consumes CPU cycles while waiting. Consider using a condition variable or a semaphore to block the thread until all threads are ready.

2. **Mutex locking**: In the `all_threads_running` function, you're locking the mutex even when it's not necessary. If you first check `if (*total_running_threads != no_of_philos)` before locking the mutex, you can avoid unnecessary locking and unlocking, which are relatively expensive operations.

3. **Avoid unnecessary computation**: In the `avoid_having_two_stright_meal` function, you're checking `if (philo->feast->inputs.no_of_philos % 2 == 0)` for each philosopher. Since the number of philosophers doesn't change, you could calculate this once and store the result, rather than calculating it for each philosopher.

Here's how you might modify your code to incorporate these suggestions:

```c
void	all_threads_created(t_feast *feast)
{
	pthread_mutex_lock(&feast->feast_mutex);
	while (!feast->all_threads_ready)
		pthread_cond_wait(&feast->all_threads_ready_cond, &feast->feast_mutex);
	pthread_mutex_unlock(&feast->feast_mutex);
}

bool	all_threads_running(t_mutex *mutex, long *total_running_threads,
		long no_of_philos)
{
	if (*total_running_threads != no_of_philos)
	{
		mutex_handle(mutex, LOCK);
		bool res = (*total_running_threads == no_of_philos);
		mutex_handle(mutex, UNLOCK);
		return res;
	}
	return false;
}

void	avoid_having_two_stright_meal(t_philo *philo)
{
	static bool is_even = false;
	static bool is_even_calculated = false;

	if (!is_even_calculated)
	{
		is_even = (philo->feast->inputs.no_of_philos % 2 == 0);
		is_even_calculated = true;
	}

	if (is_even)
	{
		if (philo->parity == EVEN)
			sleep_well(3e4, philo->feast);
	}
	else
	{
		if (philo->parity == ODD)
			fucking_think(philo, true);
	}
}
```

Please note that you'll need to initialize `all_threads_ready_cond` with `pthread_cond_init` somewhere in your code. Also, these changes assume that `mutex_handle` is a wrapper around `pthread_mutex_lock` and `pthread_mutex_unlock`, and that `LOCK` and `UNLOCK` are the correct arguments for locking and unlocking a mutex, respectively.