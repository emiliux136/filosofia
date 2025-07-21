/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:53:06 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/21 16:54:38 by emilgarc         ###   ########.fr       */
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

void	fork_order(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_print(MGT "has taken a fork" RS, philo, philo->id);
		pthread_mutex_lock(philo->r_fork);
		ft_print(B_MGT "has taken a fork" RS, philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print(MGT "has taken a fork" RS, philo, philo->id);
		pthread_mutex_lock(philo->l_fork);
		ft_print(B_MGT "has taken a fork" RS, philo, philo->id);
	}
}

void	eat(t_philo *philo)
{
	if (philo->num_philos == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		ft_print(MGT "has taken a fork" RS, philo, philo->id);
		ft_usleep(philo->timetodie);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	fork_order(philo);
	philo->eating = 1;
	ft_print(YLW "is eating" RS, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->timetoeat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	zzz(t_philo *philo)
{
	ft_print(BLU "is sleeping" RS, philo, philo->id);
	ft_usleep(philo->timetosleep);
}

void	think(t_philo *philo)
{
	ft_print(GRE "is thinking" RS, philo, philo->id);
}
