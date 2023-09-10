/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:08:22 by jdubilla          #+#    #+#             */
/*   Updated: 2022/04/08 21:38:37 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void	exec_multiple_pipe_here_doc(char **argv, char **envp, int i)
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
		wait(NULL);
	}
}

void	pipex_here_doc(int argc, char **argv, char **envp, int fileout)
{
	int	i;

	i = 3;
	if (fileout == -1)
		error();
	while (i < argc - 2)
	{
		exec_multiple_pipe_here_doc(argv, envp, i);
		i++;
	}
	dup2(fileout, STDOUT_FILENO);
	execute_cmd(argv[i], envp);
}

static void	wait_good_line(char **argv, int *fd)
{
	char	*str;

	str = get_next_line(STDIN_FILENO, 0);
	if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
	{
		free(str);
		get_next_line(STDIN_FILENO, 42);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd(str, fd[1]);
	free (str);
}

void	here_doc(char **argv, int argc, int fileout, char **envp)
{
	int		pid;
	int		fd[2];

	if (argc != 6)
		ft_printf("Nombre incorrect d'arguments\n");
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
			wait_good_line(argv, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
	pipex_here_doc(argc, argv, envp, fileout);
}
