/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:36 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:02:37 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sa(t_stacks *stacks)
{
	swap(stacks->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->stack_b);
	swap(stacks->stack_a);
	write(1, "ss\n", 3);
}
