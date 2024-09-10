/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:20 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:22 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef size_t	t_timestamp;

typedef struct s_fork
{
	char			claimed;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_env
{
	pthread_mutex_t	print_lock;
	pthread_mutex_t	value_lock;
	t_timestamp		start_time;
	t_timestamp		sleep_time;
	t_timestamp		eat_time;
	t_timestamp		death_time;
	int				count;
	int				max_meals;
	char			running;
	t_fork			*forks;
}	t_env;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	t_env		*env;
	t_timestamp	last_meal;
	pthread_t	thread_id;
}	t_philo;

t_philo		*init(char**av, t_env *env);
void		free_all(t_env *env, int i);

t_timestamp	time_offset(t_timestamp start);
int			check_continue(t_philo *philo);
void		msleep(t_philo *philo, t_timestamp ms);

void		*philo(void *ptr);
void		eat(t_philo *philo);
void		grab_fork(t_philo *philo, int id);
void		drop_fork(t_philo *philo, int id);

void		print_taking_fork(t_philo *philo);
void		print_eating(t_philo *philo);
void		print_sleeping(t_philo *philo);
void		print_thinking(t_philo *philo);
void		print_death(t_philo *philo);

#endif
