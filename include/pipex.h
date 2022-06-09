/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:51:45 by mmaric            #+#    #+#             */
/*   Updated: 2022/06/07 15:30:02 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

char	*find_path(char *cmd, char **envp);
void	to_exec(char *cmd, char **envp);
void	processfils1(char **argv, char **envp, int *fd);
void	processfils2(char **argv, char **envp, int *fd);
void	processparent(pid_t child1, pid_t child2, int *fd, int *error);
void	ft_err(void);
int 	check_cmd(char *cmd);
void	parent(int in, int out, int *fd);
void	print_err(char *error, char *cmd);
int 	check_access(char *fd);

#endif