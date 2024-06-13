char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			res = (char *)&s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		res = (char *)&s[i];
	return (res);
}
