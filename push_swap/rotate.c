/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:02:14 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/16 17:02:15 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ra(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
	write(1, "rr\n", 3);
}
