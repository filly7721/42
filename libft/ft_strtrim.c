#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (j >= i && ft_strchr(set, s1[j]))
		j--;
	j++;
	res = malloc(sizeof(char) * (j - i + 1));
	if (res)
		ft_strlcpy(res, &s1[i], j - i + 1);
	return (res);
}
