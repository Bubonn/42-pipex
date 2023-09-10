/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:46:25 by jdubilla          #+#    #+#             */
/*   Updated: 2022/03/08 13:32:24 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_new_tab(char *str, char *line)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_lenline(line);
	while (str[i + len])
	{
		str[i] = str[i + len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_line(char *str, char *line)
{
	int		i;
	int		len;
	char	*res;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_lenline(str);
	if (!len)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

char	*ft_file_to_tab(int fd, char *str)
{
	int		oct_read;
	char	*buff;

	oct_read = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (oct_read > 0 && (ft_strchr_bis(str, '\n') == 0))
	{
		oct_read = read(fd, buff, BUFFER_SIZE);
		if (oct_read == -1 || (oct_read == 0 && !str))
		{
			free(buff);
			return (NULL);
		}
		buff[oct_read] = '\0';
		str = ft_strjoin_bis(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd, int exit)
{
	static char	*str;
	static int	i;
	char		*line;

	if (exit == 42)
	{
		free(str);
		i = 1;
		return (NULL);
	}
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || i == 1)
		return (NULL);
	str = ft_file_to_tab(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str, line);
	if (!line)
	{
		free(str);
		i = 1;
		return (NULL);
	}
	str = ft_new_tab(str, line);
	return (line);
}
