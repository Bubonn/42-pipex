/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:33:35 by jdubilla          #+#    #+#             */
/*   Updated: 2021/11/29 14:49:54 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(*res) * (len + 2));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[++j] = s1[i];
	i = -1;
	res[++j] = '/';
	while (s2[++i])
		res[++j] = s2[i];
	j++;
	res[j] = '\0';
	return (res);
}

/*#include <stdio.h>
int main()
{
	char tab[] = "tripouille";
	char tab2[] = "42";
	printf("%s", ft_strjoin(tab, tab2));
}*/
