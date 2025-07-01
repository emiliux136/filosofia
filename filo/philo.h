/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:06:55 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/01 16:37:29 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 0
# define FALSE 1

# define W_ARG "Wrong arguments, it should be 5 or 6 values.\n"
# define W_MALLOC "Malloc error\n"
# define W_PHILO_NBR "Invalid philosophers number\n"
# define W_TIME_DIE "Invalid time to die\n"
# define W_TIME_EAT "Invalid time to eat\n"
# define W_TIME_SLEEP "Invalid time to sleep\n"
# define W_NBR_EAT "Invalid number of times each philosopher must eat\n"

typedef struct s_philo
{
	int				id;
	int				eating;
	int				num_philos;
	int				howmanymeals;
	int				*dead;
	int				meals_eaten;
	size_t			last_meal;
	size_t			timetodie;
	size_t			timetosleep;
	size_t			timetoeat;
	size_t			startime;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
} 	t_program;

int			main(int argc, char **argv);
int			check_args(char **argv);

// UTILS

int			ft_atoi(char *str);
int			ft_aredigit(char *c);
int			ft_error(char *str, int exit, int fd);

#endif