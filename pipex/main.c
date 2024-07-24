#include "pipex.h"

void	exec(char *str, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(str, ' ');
	if (!cmd)
		error("an error has occured");
	path = get_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putend_fd(cmd[0], 2);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(-1);
	}
}

int	child(int *fds, char **av, char **env)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	dup2(infile, 0);
	dup2(fds[1], 1);
	close(fds[0]);
	exec(av[2], env);
}

int	parent(int *fds, char **av, char **env)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT);
	dup2(outfile, 1);
	dup2(fds[0], 0);
	close(fds[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fds[2];
	int	pid;
	
	//! TEMP
	if (ac < 5)
	{
		ft_putstr_fd("what do?!", 2);
	}
	pipe(fds);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		child(fds, av, env);
	else
		parent(fds, av, env);
}
