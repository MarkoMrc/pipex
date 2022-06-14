/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:51:48 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/10 16:30:02 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// faire une fonction pour la norminette
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		error;
	pid_t	child1;
	pid_t	child2;

	if (argcheck(argc) == 1)
		return (1);
	if (pipe(fd) == -1)
		perror("error");
	child1 = fork();
	if (child1 == -1)
		perror("error");
	if (child1 == 0)
		processfils1(argv, envp, fd);
	child2 = fork();
	if (child2 == -1)
		perror("error");
	if (child2 == 0)
		processfils2(argv, envp, fd);
	error = processparent(argv, child1, child2, fd);
	return (error);
}
