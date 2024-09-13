/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:36 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:37 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timestamp	time_offset(t_timestamp start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}

void	msleep(t_philo *philo, t_timestamp ms)
{
	t_timestamp	start;

	start = time_offset(philo->env->start_time);
	while (check_continue(philo)
		&& time_offset(philo->env->start_time) - start < ms)
		usleep(100);
}

static int	check_death(t_philo *philo)
{
	int	running;

	pthread_mutex_lock(&philo->env->value_lock);
	if (philo->env->running
		&& (time_offset(philo->env->start_time) - philo->last_meal
			> philo->env->death_time))
	{
		philo->env->running = 0;
		print_death(philo);
	}
	running = philo->env->running;
	pthread_mutex_unlock(&philo->env->value_lock);
	return (running);
}

int	check_continue(t_philo *philo)
{
	int	cont;

	cont = check_death(philo);
	cont = cont
		&& (philo->env->max_meals == 0
			|| philo->meals_eaten < philo->env->max_meals);
	return (cont);
}
