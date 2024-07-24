/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:04 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:09:05 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_and_error(t_stacks	*stacks)
{
	delete_arrays(stacks);
	delete_stacks(stacks);
	write(2, "Error\n", 6);
	exit(-1);
}

int	free_and_exit(t_stacks *stacks)
{
	delete_arrays(stacks);
	delete_stacks(stacks);
	exit(0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (!create_stacks(&stacks))
		free_and_error(&stacks);
	if (!parse_input(ac - 1, av + 1, &stacks))
		free_and_error(&stacks);
	if (!check_dupes(&stacks))
		free_and_error(&stacks);
	if (is_sorted(&stacks))
		free_and_exit(&stacks);
	if (!flatten_stack(&stacks))
		free_and_error(&stacks);
	sort(&stacks);
	free_and_exit(&stacks);
}
