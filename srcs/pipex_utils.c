/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:52:14 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/13 17:28:00 by mmaric           ###   ########.fr       */
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

void	to_exec(char *argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	if (argv[0] == '\0')
		exit(127);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		exit(EXIT_FAILURE);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_perror(path, cmd);
	}
}

//check all leaks and open fd 
//valgrind --leak-check=full --track-fds=yes --trace-children=yes  env -i 

// valgrind --leak-check=full --track-fds=yes --trace-children=yes  
// --leak-check=full --show-leak-kinds=all env -i 
// ./pipex /dev/stdin "/bin/cat" "bin/wc -l" /dev/stdout
// ("usage : ./pipex file1 'cmd1' 'cmd2' file2\n");