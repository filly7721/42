/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:44:02 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/22 15:32:44 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	do_op(int a, int b, char op)
{
	void	(*funcs[5])(int a, int b);

	funcs[0] = &add;
	funcs[1] = &sub;
	funcs[2] = &mul;
	funcs[3] = &div;
	funcs[4] = &mod;
	if (op == '+')
		funcs[0](a, b);
	else if (op == '-')
		funcs[1](a, b);
	else if (op == '*')
		funcs[2](a, b);
	else if (op == '/')
		funcs[3](a, b);
	else if (op == '%')
		funcs[4](a, b);
	else
		write(1, "0", 1);
}
