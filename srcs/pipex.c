/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:51:48 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/09 15:09:04 by mmaric           ###   ########.fr       */
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

	error = 0;
	if (argcheck(argc) == 1)
		return (1);
	if (pipe(fd) == -1)
		ft_err("error");
	child1 = fork();
	if (child1 == -1)
		ft_err("error");
	if (child1 == 0)
		if (printerr(processfils1(argv, envp, fd)) != 0)
			return (1);
	child2 = fork();
	if (child2 == -1)
		ft_err("error");
	if (child2 == 0)
		if (printerr(processfils2(argv, envp, fd)) != 0)
			return (127);
	processparent(child1, child2, fd, &error);
	return (error);
}
