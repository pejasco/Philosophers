t_feast *feast = malloc(sizeof(t_feast));
feast->inputs = /* set your inputs here */;
feast->philos = malloc(sizeof(t_philo) * feast->inputs->no_of_philos);
feast->forks = malloc(sizeof(t_fork) * feast->inputs->no_of_philos);
feast->threads = malloc(sizeof(pthread_t) * feast->inputs->no_of_philos);

// Initialize the mutexes and other data for the forks and philosophers
for (int i = 0; i < feast->inputs->no_of_philos; i++) {
    feast->forks[i].fork_id = i;
    feast->forks[i].held_by_who = -1;  // -1 means the fork is not held by any philosopher
    pthread_mutex_init(&feast->forks[i].fork_mutex, NULL);

    feast->philos[i].id = i;
    feast->philos[i].left_fork = &feast->forks[i];
    feast->philos[i].right_fork = &feast->forks[(i + 1) % feast->inputs->no_of_philos];
    feast->philos[i].last_meal_start_time = 0;
    feast->philos[i].eat_count = 0;
    feast->philos[i].parity = i % 2 == 0 ? EVEN : ODD;
    feast->philos[i].life = ALIVE;
    feast->philos[i].status = THINK;
    pthread_mutex_init(&feast->philos[i].last_meal_start_time_mutex, NULL);
    pthread_mutex_init(&feast->philos[i].eat_count_mutex, NULL);
    pthread_mutex_init(&feast->philos[i].parity_mutex, NULL);
    pthread_mutex_init(&feast->philos[i].life_mutex, NULL);
}

// Create the threads for the philosophers
for (int i = 0; i < feast->inputs->no_of_philos; i++) {
    if (pthread_create(&feast->threads[i], NULL, philosopher_function, &feast->philos[i]) != 0) {
        perror("pthread_create");
        return 1;
    }
}

// Wait for all threads to finish
for (int i = 0; i < feast->inputs->no_of_philos; i++) {
    pthread_join(feast->threads[i], NULL);
}

// Don't forget to clean up when you're done!