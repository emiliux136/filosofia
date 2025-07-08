#include "philo.h"

int thread_maker(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;
	// if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
	// 	destroyer(W_THR, program, forks);
	// /* a la funcion pthread_create, tengo que pasarle otra función 
	// mas bien su direccion de memoria para que a la hora de crear 
	// el hilo la añada. Por eso voy a hacer primero la rutina */
	while (i < program->philos[0].num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &init_routine,
				&program->philos[i] != TRUE))
			destroyer(W_THR, program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroyer(W_JTHR, program, forks);
	while (i < program->philos[0].num_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroyer(W_JTHR, program, forks);
		i++;
	}
	return (0);
}

void    destroyer(char *str, t_program *program, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	ft_error(str, 1, 2);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	ft_print(char *str, t_philo *philo, int id)
{
	size_t	t;
	pthread_mutex_lock(philo->write_lock);
	t = current_time() - philo->startime;
	if (ifdead(philo) == FALSE)
		printf("%zu %d %s\n", t, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

