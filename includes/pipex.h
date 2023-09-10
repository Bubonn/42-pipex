/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:10:32 by jdubilla          #+#    #+#             */
/*   Updated: 2022/03/08 20:44:38 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

char	*get_next_line(int fd, int exit);
int		ft_strchr_bis(char *s, char c);
int		ft_lenline(char *str);
int		ft_strlen(const char *s);
int		ft_strlen_bis(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strjoin_bis(char *str, char *buff);
char	*ft_strnstr(const char *big, const char *little, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *str, char c);
void	error(void);
void	loop_wait(int argc);
void	ft_putstr_fd(char *s, int fd);
void	execute_cmd(char *cmd, char **envp);
void	here_doc(char **argv, int argc, int fileout, char **envp);

#endif
