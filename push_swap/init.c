/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:07 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:08 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(t_stacks *stacks)
{
	stacks->stack_a = malloc(sizeof(t_stack));
	stacks->stack_b = malloc(sizeof(t_stack));
	if (!stacks->stack_a || !stacks->stack_b)
		return (0);
	stacks->stack_a->arr = NULL;
	stacks->stack_b->arr = NULL;
	stacks->stack_a->size = 0;
	stacks->stack_b->size = 0;
	return (1);
}

int	create_arrays(t_stacks *stacks, int size)
{
	stacks->stack_a->arr = malloc(sizeof(int) * size);
	stacks->stack_a->size = 0;
	stacks->stack_b->arr = malloc(sizeof(int) * size);
	stacks->stack_b->size = 0;
	if (!stacks->stack_a->arr || !stacks->stack_b->arr)
		return (0);
	return (1);
}

void	delete_arrays(t_stacks *stacks)
{
	if (stacks->stack_a->arr)
		free(stacks->stack_a->arr);
	if (stacks->stack_b->arr)
		free(stacks->stack_b->arr);
}

void	delete_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
}
