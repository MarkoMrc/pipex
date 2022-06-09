/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:52:14 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/07 16:16:32 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**all_paths;
	char	*path;
	char	*to_find;

	i = 0;
	if (check_cmd(cmd) == 1 && access(cmd, X_OK) == 0)
		return (cmd);
	if (envp == NULL || *envp == NULL || *envp[i] == '\0')
		return (cmd);
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i], ':');
	if (!all_paths)
		return (0);
	i = 0;
	while (all_paths[i])
	{
		if (check_cmd(cmd) == 0)
		{
			to_find = ft_strjoin(all_paths[i], "/");
			path = ft_strjoin(to_find, cmd);
			free(to_find);
		}
		else
			path = ft_strjoin(all_paths[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
	return (NULL);
}

/* function to execute, split the argv into cmd */

// when last cmd found exit = 0 
// when last cmd not found exit = 127

void	to_exec(char *argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		print_err("Command not found: ", cmd[0]);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(127);
	}
	else if (execve(path, cmd, envp) == -1)
	{
		free(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
}

// check if it's just a cmd or if it's an absolute path
int	check_cmd(char *cmd)
{
	if (cmd[0] == '/')
		return (1);
	else
		return (0);
}

void	print_err(char *error, char *cmd)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 2);
}

void	ft_err(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

//check all leaks and open fd 
//valgrind --leak-check=full --track-fds=yes --trace-children=yes  env -i 