/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:57 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/07 16:15:30 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//read from infile, execute cmd1 with in as input
void	processfils1(char **argv, char **envp, int *fd)
{
	int	in;

	if (check_access(argv[1]) < 2)
	{
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(EXIT_FAILURE);
	}
	in = open(argv[1], O_RDONLY);
	if (in == -1)
	{
		close(in);
		exit(EXIT_FAILURE);
	}
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(in);
	to_exec(argv[2], envp);
	free(argv[2]);
}

//send the output to cmd2 -> write to outfile

void	processfils2(char **argv, char **envp, int *fd)
{
	int	out;

	if (check_access(argv[4]) != 3 && access(argv[4], F_OK) == 0)
	{
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(EXIT_FAILURE);
	}
	out = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (out == -1)
	{
		close(out);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(out);
	to_exec(argv[3], envp);
	free(argv[3]);
}

void	processparent(pid_t child1, pid_t child2, int *fd, int *error_code)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, error_code, 0);
	if (WIFEXITED(*error_code))
		exit(WEXITSTATUS(*error_code));
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
