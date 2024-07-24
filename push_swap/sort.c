/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:22 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:23 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_max(t_stack *stack)
{
	int	*arr;
	int	size;
	int	max;

	size = stack->size;
	arr = stack->arr;
	max = arr[--size];
	while (size-- > 0)
	{
		if (arr[size] > max)
			max = arr[size];
	}
	return (max);
}

void	radix_sort(t_stacks	*stacks)
{
	int	i;
	int	count;
	int	max;

	max = arr_max(stacks->stack_a);
	i = 0;
	while ((max >> i) > 0)
	{
		count = stacks->stack_a->size;
		while (count--)
		{
			if ((stacks->stack_a->arr[0] >> i & 1) == 0)
				pb(stacks);
			else
				ra(stacks);
		}
		while (stacks->stack_b->size)
			pa(stacks);
		i++;
	}
}

void	sort(t_stacks *stacks)
{
	int	length;

	length = stacks->stack_a->size;
	if (length < 2)
		return ;
	if (length <= 5)
		small_sort(stacks);
	else
		radix_sort(stacks);
}
