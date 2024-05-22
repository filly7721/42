/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:32:37 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/05 15:22:56 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

//#include <stdio.h>
//int	main()
//{
//	char src[13] = "Hello World!";
//	char dest[13] = "Gibberish...";
//	
//
//	puts(dest);
//	ft_strcpy(dest, src);
//	puts(dest);
//}
