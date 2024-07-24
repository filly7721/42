/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:25 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:02:26 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rra(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->stack_a);
	reverse_rotate(stacks->stack_b);
	write(1, "rrr\n", 4);
}
