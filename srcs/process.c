/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:20:57 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/13 17:28:26 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//read from infile, execute cmd1 with in as input
void	processfils1(char **argv, char **envp, int *fd)
{
	int	in;

	in = open(argv[1], O_RDONLY);
	if (in == -1)
	{
		perror(argv[1]);
		close(in);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(in);
	to_exec(argv[2], envp);
}

//send the output to cmd2 -> write to outfile

void	processfils2(char **argv, char **envp, int *fd)
{
	int	out;

	out = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (out == -1)
	{
		perror(argv[4]);
		close(out);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(out);
	to_exec(argv[3], envp);
}

int	processparent(char **argv, pid_t child1, pid_t child2, int *fd)
{
	int	error_code[2];

	close(fd[0]);
	close(fd[1]);
	waitpid(child1, &error_code[0], 0);
	printerr1(argv, WEXITSTATUS(error_code[0]));
	waitpid(child2, &error_code[1], 0);
	printerr2(argv, WEXITSTATUS(error_code[1]));
	return (WEXITSTATUS(error_code[1]));
}
