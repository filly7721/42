/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:43:40 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 12:43:40 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	substrcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *big,	const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	max;

	if (little[0] == '\0')
		return ((char *)big);
	if (len < ft_strlen(little))
		return (NULL);
	max = len - ft_strlen(little) + 1;
	i = 0;
	while (big[i] != '\0' && i < max)
	{
		if (substrcmp(&big[i], little) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
