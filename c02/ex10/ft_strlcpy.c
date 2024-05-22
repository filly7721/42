/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:46:49 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/05 17:45:35 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	i = 0;
	count = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
		count++;
	}
	dest[i] = '\0';
	return (count);
}

//#include <stdio.h>
//int main()
//{
//	char str1[] = "I am test, please test";
//	char str2[] = "overwrite me please!!";
//
//	puts(str2);
//	ft_strlcpy(str2, str1, 10);
//	puts(str2);
//}
