/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:41:18 by jdubilla          #+#    #+#             */
/*   Updated: 2021/11/27 18:38:00 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			res = i;
			while (big[i++] == little[j] || !little[j])
			{
				if (little[j] == '\0' && res + j <= len)
					return ((char *)big + res);
				j++;
			}
			i = res;
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", ft_strnstr("Bojonur", "", 3));
	printf("%s\n", strnstr("Bojonur", "", 3));
	printf("%s\n", ft_strnstr("Bojonur", "", 0));
	printf("%s\n", strnstr("Bojonur", "", 0));
	printf("%s\n", ft_strnstr("Bojonur", "ou", 55));
	printf("%s\n", strnstr("Bojonur", "ou", 55));
	printf("%s\n", ft_strnstr("Bojonur", "ur", 50));
	printf("%s\n", strnstr("Bojonur", "ur", 50));
}*/
