/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:51:48 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/07 16:17:15 by mmaric           ###   ########.fr       */
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
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_err();
		child1 = fork();
		if (child1 == -1)
			ft_err();
		if (child1 == 0)
			processfils1(argv, envp, fd);
		child2 = fork();
		if (child2 == -1)
			ft_err();
		if (child2 == 0)
			processfils2(argv, envp, fd);
		processparent(child1, child2, fd, &error);
	}
	else
	{
		ft_err();
		ft_putstr_fd("usage : ./pipex file1 'cmd1' 'cmd2' file2\n", 2);
	}
	return (error);
}
