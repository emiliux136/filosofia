/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:06:55 by emilgarc          #+#    #+#             */
/*   Updated: 2025/07/10 17:31:02 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define B_RED "\033[1;31m"
# define RED "\033[0;31m"
# define RS "\033[0m"

# define W_ARG "Wrong arguments, it should be 5 or 6 values.\n"
# define W_MALLOC "Malloc error\n"
# define W_PHILO_NBR "Invalid philosophers number\n"
# define W_TIME_DIE "Invalid time to die\n"
# define W_TIME_EAT "Invalid time to eat\n"
# define W_TIME_SLEEP "Invalid time to sleep\n"
# define W_NBR_EAT "Invalid number of times each philosopher must eat\n"
# define W_TIME "Problems with 'gettimeofday' funtion\n"
# define W_THR "Thread creation error\n"
# define W_JTHR "Thread join error\n"

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

// START

void		init_program(t_program *program, t_philo *philos);
void		init_forks(pthread_mutex_t *forks, char **argv);
void		*init_routine(void *ptr);
void		init_philos(t_philo *philo, pthread_mutex_t *forks,
				t_program *program);

// UTILS

int			ft_atoi(char *str);
int			ft_aredigit(char *c);
int			ft_error(char *str, int exit, int fd);
size_t		current_time(void);
int			ifdead(t_philo *philo);

// CROCHET

int			thread_maker(t_program *program, pthread_mutex_t *forks);
void		destroyer(char *str, t_program *program, pthread_mutex_t *forks);
void		ft_print(char *str, t_philo *philo, int id);

// MONITOR

int			philosopher_dead(t_philo *philo, size_t time_to_die);
int			monitor_dead_checker(t_philo *philos);
int			check_all_ate(t_philo *philos);
void		*monitor(void *ptr);

// ROUTINE

void		eat(t_philo *philo);
int			ft_usleep(size_t milis);
void		zzz(t_philo *philo);
void		think(t_philo *philo);

#endif