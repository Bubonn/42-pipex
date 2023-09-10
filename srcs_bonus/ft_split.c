/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:44:35 by jdubilla          #+#    #+#             */
/*   Updated: 2021/11/29 14:40:39 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_taillemot(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static	int	ft_nbrmots(const char *str, char c)
{
	int	i;
	int	mots;

	mots = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		i = ft_taillemot(str, c);
		str += i;
		if (i > 0)
			mots++;
	}
	return (mots);
}

static	char	*ft_cpymot(const char *src, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		tailletab;
	int		i;
	int		lenmot;

	if (!str)
		return (NULL);
	tailletab = ft_nbrmots(str, c);
	res = malloc((tailletab + 1) * sizeof(char *));
	if (!(res))
		return (NULL);
	i = -1;
	while (++i < tailletab)
	{
		while (*str && *str == c)
			str++;
		lenmot = ft_taillemot(str, c);
		res[i] = ft_cpymot(str, lenmot);
		if (!(res))
			return (NULL);
		str += lenmot;
	}
	res[tailletab] = NULL;
	return (res);
}
