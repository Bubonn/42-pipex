/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:11:26 by jdubilla          #+#    #+#             */
/*   Updated: 2022/05/02 14:37:05 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

void	error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	exec_first_pipe(char **argv, char **envp, int i)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(argv[i], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	pipex(int argc, char **argv, char **envp, int fileout)
{
	int	filein;
	int	i;

	filein = open(argv[1], O_RDONLY, 00644);
	dup2(filein, STDIN_FILENO);
	i = 2;
	while (i < argc - 2)
	{
		exec_first_pipe(argv, envp, i);
		i++;
	}
	dup2(fileout, STDOUT_FILENO);
	execute_cmd(argv[i], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fileout;

	if (argc > 1 && ft_strcmp("here_doc", argv[1]) == 0)
	{
		if (argc != 6)
		{
			ft_putstr_fd("Nombre incorrect d'arguments\n", 2);
			return (1);
		}
		fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 00644);
		here_doc(argv, argc, fileout, envp);
	}
	else if (argc >= 5)
	{
		fileout = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 00644);
		pipex(argc, argv, envp, fileout);
	}
	else
		ft_putstr_fd("Nombre incorrect d'arguments\n", 2);
	return (0);
}
