/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:32:04 by ashalaab          #+#    #+#             */
/*   Updated: 2024/09/09 16:32:05 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_env	env;
	t_philo	*philos;
	int		i;

	if (ac < 5 || ac > 6)
		return (
			printf("./philo number_of_philosophers time_to_die"),
			printf(" time_to_eat time_to_sleep [meal_count]\n")
			, 1);
	philos = init(av, &env);
	if (!philos)
		(printf("an error has occured\n"), exit(1));
	i = -1;
	while (++i < env.count)
		pthread_create(&philos[i].thread_id, NULL, philo, &philos[i]);
	i = -1;
	while (++i < env.count)
		pthread_join(philos[i].thread_id, NULL);
	free_all(&env, env.count);
	free(philos);
}
