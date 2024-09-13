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
	pthread_mutex_lock(&philo->env->print_lock);
	if (philo->env->running)
		printf("%zu %i \e[33mhas taken a fork\e[0m\n",
			time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
	pthread_mutex_unlock(&philo->env->value_lock);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	if (philo->env->running)
		printf("%zu %i \e[32mis eating\e[0m\n",
			time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
	pthread_mutex_unlock(&philo->env->value_lock);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	if (philo->env->running)
		printf("%zu %i \e[34mis sleeping\e[0m\n",
			time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
	pthread_mutex_unlock(&philo->env->value_lock);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->value_lock);
	pthread_mutex_lock(&philo->env->print_lock);
	if (philo->env->running)
		printf("%zu %i \e[35mis thinking\e[0m\n",
			time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
	pthread_mutex_unlock(&philo->env->value_lock);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->print_lock);
	printf("%zu %i \e[31mdied\e[0m\n",
		time_offset(philo->env->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->env->print_lock);
}
