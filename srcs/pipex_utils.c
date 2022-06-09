/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:52:14 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/09 15:04:31 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**all_paths;
	char	*path;

	i = 0;
	if ((check_cmd(cmd) == 1)
		|| (envp == NULL || *envp == NULL || *envp[i] == '\0'))
		return (cmd);
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i], ':');
	if (!all_paths)
		return (NULL);
	i = 0;
	path = ft_path(all_paths, cmd);
	if (path)
	{
		ft_free(all_paths);
		return (path);
	}
	ft_free(all_paths);
	return (NULL);
}

char	*ft_path(char **str, char *cmd)
{
	char	*path;
	char	*to_find;
	int		i;

	i = 0;
	while (str[i])
	{
		to_find = ft_strjoin(str[i], "/");
		if (!to_find)
			return (NULL);
		path = ft_strjoin(to_find, cmd);
		if (!path)
			return (NULL);
		free(to_find);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

/* function to execute, split the argv into cmd */

// when last cmd found exit = 0 
// when last cmd not found exit = 127

int	to_exec(char *argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd)
		return (1);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd(cmd[0], 2);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		return (127);
	}
	else if (execve(path, cmd, envp) == -1)
	{
		free(cmd);
		free(path);
		return (1);
	}
	return (0);
}

//check all leaks and open fd 
//valgrind --leak-check=full --track-fds=yes --trace-children=yes  env -i 

// valgrind --leak-check=full --track-fds=yes --trace-children=yes  
// --leak-check=full --show-leak-kinds=all env -i 
// ./pipex /dev/stdin "/bin/cat" "bin/wc -l" /dev/stdout
// ("usage : ./pipex file1 'cmd1' 'cmd2' file2\n");