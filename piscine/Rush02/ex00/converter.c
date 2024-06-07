/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:19:22 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:33:53 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	handle_tens(int tens, int ones, t_data *data)
{
	if (tens > 1)
	{
		if (!data->parsed_dict_20[tens - 2])
			return (0);
		add_to_res(data->parsed_dict_rest[tens - 2], data);
	}
	else if (tens == 1)
	{
		if (!data->parsed_dict_20[tens * 10 + ones])
			return (0);
		add_to_res(data->parsed_dict_20[tens * 10 + ones], data);
	}
	if (ones && tens < 1)
	{
		if (!data->parsed_dict_20[ones])
			return (0);
		add_to_res(data->parsed_dict_20[ones], data);
	}
	return (1);
}

static int	handle_hundreds(int hundreds, t_data *data)
{
	if (data->parsed_dict_20[hundreds])
	{
		add_to_res(data->parsed_dict_20[hundreds], data);
		add_to_res(get_string_type(HUNDRED), data);
		return (1);
	}
	return (0);
}

static int	handle_num(long num, int type, t_data *data)
{
	int	hundreds;
	int	tens;
	int	ones;

	hundreds = num / 100;
	tens = num / 10 % 10;
	ones = num % 10;
	if (hundreds)
	{
		if (!handle_hundreds(hundreds, data))
			return (0);
	}
	if (tens)
	{
		if (!handle_tens(tens, ones, data))
			return (0);
	}
	if (ones && tens != 1)
		add_to_res(data->parsed_dict_20[ones], data);
	add_to_res(get_string_type(type), data);
	return (1);
}

int	convert(char *to_convert, t_data *data)
{
	long		num;

	num = check_for_minus(ft_atoi(to_convert), data);
	if (num == 0)
	{
		if (!data->parsed_dict_20[0])
			return (print_error_and_return_zero(1));
		ft_putstr(data->parsed_dict_20[0]);
	}
	if (num >= BILLION)
		if (!handle_num(num / BILLION, BILLION, data))
			return (print_error_and_return_zero(1));
	if (num >= MILLION)
		if (!handle_num(num / MILLION % THOUSAND, MILLION, data))
			return (print_error_and_return_zero(1));
	if (num >= THOUSAND)
		if (!handle_num(num / THOUSAND % THOUSAND, THOUSAND, data))
			return (print_error_and_return_zero(1));
	if (!handle_num(num % 1000, 10, data))
		return (print_error_and_return_zero(1));
	return (1);
}
