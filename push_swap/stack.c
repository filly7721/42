/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:32 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:02:33 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = temp;
}

void	push(t_stack *stack, int num)
{
	stack->arr[stack->size++] = num;
	reverse_rotate(stack);
}

int	pop(t_stack *stack)
{
	rotate(stack);
	return (stack->arr[--stack->size]);
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->arr[stack->size - 1];
	i = stack->size;
	while (--i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
	}
	stack->arr[0] = temp;
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->arr[0];
	i = 0;
	while (++i < stack->size)
	{
		stack->arr[i - 1] = stack->arr[i];
	}
	stack->arr[i - 1] = temp;
}
