/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:45:52 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/14 12:45:53 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nums(int *nums, int max)
{
	int		i;
	char	c;

	i = max - 1;
	while (i >= 0)
	{
		c = nums[i] + '0';
		write(1, &c, 1);
		i--;
	}
	i = 1;
	if (nums[0] != 9)
	{
		write(1, ", ", 2);
		return ;
	}
	while (i < max)
	{
		if (nums[i] != nums[i - 1] - 1)
		{
			write(1, ", ", 2);
			return ;
		}
		i++;
	}
}

void	rec_print_combn(int n, int *nums, int max)
{
	if (n < 0)
		return ;
	if (n == 0)
	{
		print_nums(nums, max);
		return ;
	}
	if (n == max)
		nums[n - 1] = 0;
	else
		nums[n - 1] = nums[n] + 1;
	while (nums[n - 1] < 10)
	{
		rec_print_combn(n - 1, nums, max);
		nums[n - 1]++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	nums[10];

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < 10)
		nums[i++] = 0;
	rec_print_combn(n, nums, n);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 		ft_print_combn(argv[1][0] - '0');
// }