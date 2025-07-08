#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
}