/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:16:54 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/13 17:27:22 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// check if it's just a cmd or if it's an absolute path
int	check_cmd(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}

int	argcheck(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage : ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
		return (1);
	}
	return (0);
}

void	free_perror(char *path, char **cmd)
{
	if (access(path, X_OK) == -1 && access(path, F_OK) == 0)
	{
		perror(*cmd);
		free(path);
		free(cmd);
		exit(126);
	}
	else
	{
		perror(*cmd);
		free(path);
		free(cmd);
		exit(1);
	}
}

int	printerr1(char **argv, int i)
{
	if (i == 127)
	{	
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(" : Command not found\n", 2);
		return (127);
	}
	return (0);
}

int	printerr2(char **argv, int i)
{
	if (i == 127)
	{	
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(" : Command not found\n", 2);
		return (127);
	}
	return (0);
}
