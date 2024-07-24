/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:19 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:19 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stacks *stacks)
{
	if (stacks->stack_a->arr[2] != 2)
	{
		if (stacks->stack_a->arr[0] == 2)
			ra(stacks);
		else
			rra(stacks);
	}
	if (stacks->stack_a->arr[0] > stacks->stack_a->arr[1])
		sa(stacks);
}

static void	sort_4(t_stacks *stacks)
{
	while (stacks->stack_b->size <= 1)
	{
		if (stacks->stack_a->arr[0] == 0 || stacks->stack_a->arr[0] == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->stack_b->arr[0] == 0)
		sb(stacks);
	if (stacks->stack_a->arr[0] == 3)
		sa(stacks);
	pa(stacks);
	pa(stacks);
}

static void	sort_5(t_stacks *stacks)
{
	while (stacks->stack_b->size <= 1)
	{
		if (stacks->stack_a->arr[0] == 0 || stacks->stack_a->arr[0] == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	if (stacks->stack_b->arr[0] == 0)
		sb(stacks);
	if (stacks->stack_a->arr[2] != 4)
	{
		if (stacks->stack_a->arr[0] == 4)
			ra(stacks);
		else
			rra(stacks);
	}
	if (stacks->stack_a->arr[0] > stacks->stack_a->arr[1])
		sa(stacks);
	pa(stacks);
	pa(stacks);
}

void	small_sort(t_stacks *stacks)
{
	if (stacks->stack_a->size == 2)
		sa(stacks);
	else if (stacks->stack_a->size == 3)
		sort_3(stacks);
	else if (stacks->stack_a->size == 4)
		sort_4(stacks);
	else
		sort_5(stacks);
	return ;
}
