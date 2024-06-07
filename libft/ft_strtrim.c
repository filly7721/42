#include "libft.h"

static int	check_set(char c, char const *set)
{
	int i;
	
	i = 0;
	while	(set[i] != '\0' && set[i] != c)
		i++;
	return (set[i] == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*res;

	size = 0;
	i = 0;
	while (s1[i] != '\0')
		if (!check_set(s1[i++], set))
			size++;
	res = malloc(sizeof(char) * (size + 1));
	size = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if(!check_set(s1[i], set))
			res[size++] = s1[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}