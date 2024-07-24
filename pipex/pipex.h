#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

//! TEMP
# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

char	*get_path(char *cmd, char **env);

#endif