/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:26 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:27 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_taking_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	if (philo->env->running == 0)
	{
		pthread_mutex_unlock(&philo->env->value_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i has taken a fork\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	if (philo->env->running == 0)
	{
		pthread_mutex_unlock(&philo->env->value_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i is eating\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	if (philo->env->running == 0)
	{
		pthread_mutex_unlock(&philo->env->value_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i is sleeping\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	if (philo->env->running == 0)
	{
		pthread_mutex_unlock(&philo->env->value_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i is thinking\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i died\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}
