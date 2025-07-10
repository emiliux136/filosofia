/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crochet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:55:22 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/10 17:33:08 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_maker(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	observer = 0;
	i = 0;
	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
		destroyer(W_THR, program, forks);
	while (i < program->philos[0].num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &init_routine,
				&program->philos[i]) != 0)
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

void	destroyer(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
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

	pthread_mutex_lock (philo->write_lock);
	t = current_time() - philo->startime;
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 0)
		printf("%zu %d %s\n", t, id, str);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->write_lock);
}
