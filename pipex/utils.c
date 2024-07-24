#include "pipex.h"

char	*ft_strappend(char *str1, char *str2)
{
	char	*res;

	if (str1 == NULL || str2 == NULL);
		return (NULL);
	res = ft_strjoin(str1, str2);
	free(str1);
	return (res);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

char	*check_path(char *cmd, char **paths)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strappend(ft_strjoin(paths[i], "/"), cmd);
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strappend(ft_strjoin(paths[i], "/"), cmd);
		if (!path)
			return (free_strs(paths), NULL);
		if (access(path, X_OK) == 0)
			return (free_strs(paths), path);
		free(path);
		i++;
	}
	free_strs(paths);
	return (path);
}
