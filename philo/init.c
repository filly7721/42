/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:00 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:01 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_num(char *str, int *status)
{
	int	i;
	int	sign;
	int	res;

	if (!str)
		return (0);
	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		*status = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] != '\0')
		*status = 0;
	return (sign * res);
}

static t_philo	*init_philos(t_env *env)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * env->count);
	i = 0;
	while (i < env->count)
	{
		philos[i].id = i;
		philos[i].env = env;
		philos[i].last_meal = time_offset(env->start_time);
		philos[i].meals_eaten = 0;
		i++;
	}
	return (philos);
}

static int	parse_input(char **av, t_env *env)
{
	int	success;

	success = 1;
	env->start_time = time_offset(0);
	env->running = 1;
	env->count = parse_num(av[1], &success);
	env->death_time = parse_num(av[2], &success);
	env->eat_time = parse_num(av[3], &success);
	env->sleep_time = parse_num(av[4], &success);
	env->max_meals = parse_num(av[5], &success);
	if (!success)
		return (printf("Invalid input\n"), 0);
	env->forks = malloc(sizeof(t_fork) * env->count);
	if (!env->forks)
		return (0);
	return (1);
}

void	free_all(t_env *env, int i)
{
	pthread_mutex_destroy(&env->print_lock);
	pthread_mutex_destroy(&env->value_lock);
	if (i--)
		pthread_mutex_destroy(&env->forks[i].lock);
	free(env->forks);
}

t_philo	*init(char**av, t_env *env)
{
	t_philo	*philos;
	int		i;

	i = 0;
	if (pthread_mutex_init(&env->print_lock, NULL))
		return (NULL);
	if (pthread_mutex_init(&env->value_lock, NULL))
		return (pthread_mutex_destroy(&env->print_lock), NULL);
	if (!parse_input(av, env))
		return (NULL);
	while (i < env->count)
	{
		env->forks[i].claimed = 0;
		if (pthread_mutex_init(&env->forks[i].lock, NULL))
			return (free_all(env, i), NULL);
		i++;
	}
	philos = init_philos(env);
	if (!philos)
		return (free_all(env, i), NULL);
	return (philos);
}
