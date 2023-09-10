/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:44:51 by jdubilla          #+#    #+#             */
/*   Updated: 2022/02/12 19:01:38 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	else
	{
		while (s[i])
			i++;
	}
	return (i);
}

/*int main()
  {
  printf("%ld\n", ft_strlen("Bonjour"));
  printf("%ld\n", ft_strlen("hello"));
  printf("%ld\n", ft_strlen("hey"));
  printf("%ld\n", ft_strlen("Bonjourr"));
  }*/
