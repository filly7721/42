/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:10 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo, int id)
{
	int	done;

	done = 0;
	while (check_continue(philo) && !done)
	{
		pthread_mutex_lock(&philo->env->forks[id].lock);
		done = philo->env->forks[id].claimed == 0;
		if (done)
			philo->env->forks[id].claimed = 1;
		pthread_mutex_unlock(&philo->env->forks[id].lock);
		if (!done)
			usleep(250);
	}
	print_taking_fork(philo);
}

void	drop_fork(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->env->forks[id].lock);
	philo->env->forks[id].claimed = 0;
	pthread_mutex_unlock(&philo->env->forks[id].lock);
}

void	*philo(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	msleep(philo, ((philo->id + 1) % 2) * (philo->env->eat_time / 4));
	while (check_continue(philo))
	{
		grab_fork(philo, philo->id % philo->env->count);
		grab_fork(philo, (philo->id + 1) % philo->env->count);
		print_eating(philo);
		philo->last_meal = time_offset(philo->env->start_time);
		msleep(philo, philo->env->eat_time);
		philo->meals_eaten++;
		if (check_continue(philo))
			print_sleeping(philo);
		drop_fork(philo, philo->id % philo->env->count);
		drop_fork(philo, (philo->id + 1) % philo->env->count);
		if (!check_continue(philo))
			break ;
		msleep(philo, philo->env->sleep_time);
		print_thinking(philo);
	}
	return (NULL);
}
