/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:43:40 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 12:43:40 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;

	if (ft_strlen(s) < start)
		size = 1;
	else if (ft_strlen(s) < len)
		size = ft_strlen(s) + 1;
	else if (ft_strlen(s) - start < len)
		size = len - start + 1;
	else
		size = len + 1;
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	if (size == 1)
		res[0] = '\0';
	else
		ft_strlcpy(res, s + start, size);
	return (res);
}
