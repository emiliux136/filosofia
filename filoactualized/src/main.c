/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:19 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/10 18:00:03 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	int	error;

	error = 0;
	if (ft_atoi(argv[1]) <= 0 || ft_aredigit(argv[1]) == TRUE)
		error += ft_error(RED W_PHILO_NBR RS, 1, 2);
	if (ft_atoi(argv[2]) <= 0 || ft_aredigit(argv[2]) == TRUE)
		error += ft_error(RED W_TIME_DIE RS, 1, 2);
	if (ft_atoi(argv[3]) <= 0 || ft_aredigit(argv[3]) == TRUE)
		error += ft_error(RED W_TIME_EAT RS, 1, 2);
	if (ft_atoi(argv[4]) <= 0 || ft_aredigit(argv[4]) == TRUE)
		error += ft_error(RED W_TIME_SLEEP RS, 1, 2);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || ft_aredigit(argv[5]) == TRUE))
		error += ft_error(RED W_NBR_EAT RS, 1, 2);
	if (error > 0)
		printf (B_RED "SOMETHING WENT WRONG! THERE ARE %d ERRORS\n" RS, error);
	return (error);
}

void	init_menu(t_philo *philo, pthread_mutex_t *forks, char **argv)
{
	int			i;
	t_program	program;

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
	thread_maker(&program, forks);
	destroyer(NULL, &program, forks);
	free(philo);
	free(forks);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (ft_error(RED W_ARG RS, 1, 2));
	if (check_args(argv) != 0)
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
	return (0);
}
