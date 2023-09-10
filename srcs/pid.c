/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:18:16 by jdubilla          #+#    #+#             */
/*   Updated: 2022/03/07 13:26:25 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	free_split(char **tab_a)
{
	int	i;

	i = 0;
	while (tab_a[i])
	{
		free(tab_a[i]);
		i++;
	}
	free(tab_a);
}

char	*check_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			return (envp[i] + 5);
		i++;
	}
	ft_putstr_fd("PATH introuvable\n", 2);
	exit(EXIT_FAILURE);
	return (NULL);
}

void	path_error(char **tab_cmd, char **path_split)
{
	ft_printf("command not found: %s", tab_cmd[0]);
	if (tab_cmd[1] != NULL)
		ft_printf(" %s", tab_cmd[1]);
	ft_printf("\n");
	free_split(tab_cmd);
	free_split(path_split);
	exit(127);
}

void	execute_cmd_bis(char **tab_cmd, char **envp, char **path_split)
{
	int		i;
	char	*test_path;

	i = 0;
	while (path_split[i])
	{
		test_path = ft_strjoin(path_split[i], tab_cmd[0]);
		if (*tab_cmd != NULL && access(test_path, F_OK | X_OK) == 0)
		{
			execve(test_path, tab_cmd, envp);
			free(test_path);
			free_split(tab_cmd);
			free_split(path_split);
			return ;
		}
		free(test_path);
		i++;
		if (path_split[i] == NULL)
			path_error(tab_cmd, path_split);
	}
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*path_envp;
	char	**path_split;
	char	**tab_cmd;

	tab_cmd = ft_split(cmd, ' ');
	if (access(cmd, F_OK | X_OK) == 0)
	{
		execve(cmd, tab_cmd, envp);
		free_split(tab_cmd);
		exit (EXIT_SUCCESS);
	}
	path_envp = check_envp(envp);
	path_split = ft_split(path_envp, ':');
	execute_cmd_bis(tab_cmd, envp, path_split);
}
