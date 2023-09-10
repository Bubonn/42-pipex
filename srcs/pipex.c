/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:11:26 by jdubilla          #+#    #+#             */
/*   Updated: 2022/03/08 13:25:37 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void	pid_child(char **argv, int *fd, char **envp)
{
	int	file;

	file = open(argv[1], O_RDONLY, 00777);
	if (file == -1)
	{
		ft_printf("no such file or directory: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	execute_cmd(argv[2], envp);
}

void	pid_parent(char **argv, int *fd, char **envp)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00664);
	if (file == -1)
	{
		ft_printf("no such file or directory: %s\n", argv[4]);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	execute_cmd(argv[3], envp);
}

void	error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	pipex(char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	int	pid2;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		pid_child(argv, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		pid_parent(argv, fd, envp);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv, envp);
	else
	{
		ft_putstr_fd("Nombre incorrect d'arguments\n", 2);
		return (1);
	}
	return (0);
}
