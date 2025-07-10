/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:53:06 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/10 17:36:36 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milis)
{
	size_t	start;

	start = current_time();
	while (current_time() - start < milis)
		usleep(500);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print("has taken a fork", philo, philo->id);
	if (philo->num_philos == 1)
	{
		ft_usleep(philo->timetodie);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	ft_print("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_print("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->timetoeat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	zzz(t_philo *philo)
{
	ft_print("is sleeping", philo, philo->id);
	ft_usleep(philo->timetosleep);
}

void	think(t_philo *philo)
{
	ft_print("is thinking", philo, philo->id);
}
