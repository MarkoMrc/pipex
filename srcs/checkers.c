/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:16:54 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/09 15:03:01 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// check if it's just a cmd or if it's an absolute path
int	check_cmd(char *cmd)
{
	if (cmd[0] == '/')
		return (1);
	else if (cmd[0] == '\0')
		return (2);
	else
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

int	check_access(char *fd)
{
	if (access(fd, F_OK) == 0)
	{
		if (access(fd, R_OK) == 0)
		{
			if (access(fd, W_OK) == 0)
				return (3);
			return (2);
		}
		return (1);
	}
	else
		return (0);
}

void	ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	printerr(int i)
{
	if (i == 1)
		return (1);
	if (i == 3)
	{
		ft_putstr_fd(" : Permission denied\n", 2);
		return (1);
	}
	if (i == 127)
	{	
		ft_putstr_fd(" : Command not found\n", 2);
		return (127);
	}
	if (i == 4)
	{	
		ft_putstr_fd(" : No such file or directory\n", 2);
		return (1);
	}
	return (0);
}
