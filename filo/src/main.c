/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:19 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/08 12:49:49 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	int	error;

	error = 0;
	if (ft_atoi(argv[1]) <= 0 || ft_aredigit(argv[1]) == FALSE)
		error += ft_error(W_PHILO_NBR, 1, 2);
	if (ft_atoi(argv[2]) <= 0 || ft_aredigit(argv[2]) == FALSE)
		error += ft_error(W_TIME_DIE, 1, 2);
	if (ft_atoi(argv[3]) <= 0 || ft_aredigit(argv[3]) == FALSE)
		error += ft_error(W_TIME_EAT, 1, 2);
	if (ft_atoi(argv[4]) <= 0 || ft_aredigit(argv[4]) == FALSE)
		error += ft_error(W_TIME_SLEEP, 1, 2);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || ft_aredigit(argv[5]) == FALSE))
		error += ft_error(W_NBR_EAT, 1, 2);
	printf (B_RED "SOMETHING WENT WRONG! THERE ARE %d ERRORS\n" RS, error);
	return (error);
}

void	init_menu(t_philo *philo, pthread_mutex_t *forks, char **argv)
{
	int	i;
	t_program		program;

	i = 0;
	init_program(&program, philo);
	init_forks(forks, argv);
	while (i < ft_atoi(argv[1]))
	{
		philo[i].num_philos = ft_atoi(argv[1]);
		philo[i].timetodie = ft_atoi(argv[2]);
		philo[i].timetoeat = ft_atoi(argv[3]);
		philo[i].timetosleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].howmanymeals = ft_atoi(argv[5]);
		else
			philo[i].howmanymeals = -1;
		i++;
	}
	init_philos(philo, forks, &program);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (ft_error(W_ARG, 1, 2));
	if (check_args(argv) != TRUE)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (ft_error(W_MALLOC, 1, 2));
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!forks)
	{
		free(philo);
		return (ft_error(W_MALLOC, 1, 2));
	}
	init_menu(philo, forks, argv);
	free(philo);
	free(forks);
	return (0);
}
