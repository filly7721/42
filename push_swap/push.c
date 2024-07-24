/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:02:10 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stacks *stacks)
{
	push(stacks->stack_a, pop(stacks->stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	push(stacks->stack_b, pop(stacks->stack_a));
	write(1, "pb\n", 3);
}
