/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:44:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 19:44:10 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	op;

	if (argc != 4)
		return (-1);
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	op = argv[2][0];
	do_op(x, y, op);
}
