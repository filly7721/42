/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:01 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:02 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dupes(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->stack_a->size)
	{
		j = i + 1;
		while (j < stacks->stack_a->size)
		{
			if (stacks->stack_a->arr[i] == stacks->stack_a->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (++i < stacks->stack_a->size)
		if (stacks->stack_a->arr[i] < stacks->stack_a->arr[i - 1])
			return (0);
	return (1);
}

static int	*sorted_copy(int *arr, int size)
{
	int	i;
	int	j;
	int	*copy;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = -1;
	while (i++ < size)
		copy[i] = arr[i];
	i = 0;
	while (++i < size)
	{
		j = 0;
		while (++j < size)
		{
			if (copy[j] < copy[j - 1])
			{
				copy[j] ^= copy[j - 1];
				copy[j - 1] ^= copy[j];
				copy[j] ^= copy[j - 1];
			}
		}
	}
	return (copy);
}

int	flatten_stack(t_stacks *stacks)
{
	int	i;
	int	j;
	int	*sorted;

	sorted = sorted_copy(stacks->stack_a->arr, stacks->stack_a->size);
	if (!sorted)
		return (0);
	i = -1;
	while (++i < stacks->stack_a->size)
	{
		j = -1;
		while (++j < stacks->stack_a->size)
		{
			if (stacks->stack_a->arr[i] == sorted[j])
			{
				stacks->stack_a->arr[i] = j;
				break ;
			}
		}
	}
	free(sorted);
	return (1);
}
