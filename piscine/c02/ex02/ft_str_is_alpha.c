/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:45:15 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/03 18:29:57 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (*str < 'A')
			return (0);
		if (*str > 'Z' && *str < 'a')
			return (0);
		if (*str > 'z')
			return (0);
		str++;
	}
	return (1);
}

//#include <stdio.h>
//int main()
//{
//
// printf("%d", ft_str_is_alpha("Hello"));
//}
