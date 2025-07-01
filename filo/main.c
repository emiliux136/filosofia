/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:19 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/01 16:42:53 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > 300 || ft_atoi(argv[1]) <= 0 
		|| ft_aredigit(argv[1]) == FALSE)
		return (ft_error(W_PHILO_NBR, 1, 2));
	if (ft_atoi(argv[2]) <= 0 || ft_aredigit(argv[2]) == FALSE)
		return (ft_error(W_TIME_DIE, 1, 2));
	if (ft_atoi(argv[3]) <= 0 || ft_aredigit(argv[3]) == FALSE)
		return (ft_error(W_TIME_EAT, 1, 2));
	if (ft_atoi(argv[4]) <= 0 || ft_aredigit(argv[4]) == FALSE)
		return (ft_error(W_TIME_SLEEP, 1, 2));
	if (argv[5] && (ft_atoi(argv[5]) < 0 || ft_aredigit(argv[5]) == FALSE))
		return (ft_error(W_NBR_EAT, 1, 2));
	return (TRUE);
}

void	init(t_philo *philo, pthread_mutex_t *forks,
	 t_program program, char **argv)
{
	t_program 		program;
}

int	main(int argc, char **argv)
{
t_program 		program;
t_philo 		*philo;
pthread_mutex_t *forks;

if (argc != 5 && argc != 6)
		return (ft_error(W_ARG, 1, 2));
if (check_args(argv) == TRUE)
	return(1);
philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
if (!philo)
	return (ft_error(W_MALLOC, 1, 2));
forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!forks)
	{
		free(philo);
		return (ft_error(W_MALLOC, 1, 2));
	}
free(philo);
free(forks);
return (0);
}
