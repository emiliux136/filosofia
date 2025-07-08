/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:06:55 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/08 12:50:58 by emilgarc         ###   ########.fr       */
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

# define B_RED "\033[1;31m"
# define RED "\033[0;31m"
# define RS "\033[0m"

# define W_ARG RED"Wrong arguments, it should be 5 or 6 values.\n" RS
# define W_MALLOC RED"Malloc error\n" RS
# define W_PHILO_NBR RED"Invalid philosophers number\n" RS
# define W_TIME_DIE RED"Invalid time to die \U0001f600 \n" RS
# define W_TIME_EAT RED"Invalid time to eat\n" RS
# define W_TIME_SLEEP RED"Invalid time to sleep\n" RS
# define W_NBR_EAT RED "Invalid number of times each philosopher must eat\n" RS
# define W_TIME RED "Problems with 'gettimeofday' funtion\n" RS
# define W_THR RED "Thread creation error\n" RS

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
}	t_program;

// MAIN

int			main(int argc, char **argv);
int			check_args(char **argv);
void		init_menu(t_philo *philo, pthread_mutex_t *forks, char **argv);
void		init_philos(t_philo *philo, pthread_mutex_t *forks,
				t_program *program);

// START

void		init_program(t_program *program, t_philo *philos);
void		init_forks(pthread_mutex_t *forks, char **argv);

// UTILS

int			ft_atoi(char *str);
int			ft_aredigit(char *c);
int			ft_error(char *str, int exit, int fd);
size_t		current_time(void);

// CROCHET

int			thread_maker(t_program *program, pthread_mutex_t *forks);
void		destroyer(char *str, t_program *program, pthread_mutex_t *forks);

// ROUTINE


#endif