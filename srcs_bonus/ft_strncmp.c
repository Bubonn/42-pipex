/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:17:01 by jdubilla          #+#    #+#             */
/*   Updated: 2022/02/12 19:00:09 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	else if (!s1 || !s2)
		return (1);
	else
	{
		while (i < n)
		{
			if (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
				i++;
			else
				return (1);
		}
	}
	if (s1[i] == '\n' || s1[i] == '\0')
		return (0);
	return (1);
}

/*
  int main()
  {	printf("%d\n", strncmp("Bonjour", "Bonjour", 10 ));
  printf("%d\n", ft_strncmp("Bonjour", "Bonjour", 10 ));
  printf("%d\n", strncmp("Bonjour", "Bonqour", 4));
  printf("%d\n", ft_strncmp("Bonjour", "Bonqour", 4));
  printf("%d\n", strncmp("Bonqour", "Bonjour", 10));
  printf("%d\n", ft_strncmp("Bonqour", "Bonjour", 10));
  printf("%d\n", strncmp("aa", "Baaa", 0));
  printf("%d\n", ft_strncmp("aa", "Baaa", 0));
  printf("%d\n", strncmp("Baaa", "j", 0));
  printf("%d\n", ft_strncmp("Baaa", "j", 0));
  printf("%d\n", strncmp("Bonjour", "B", 0));
  printf("%d\n", ft_strncmp("Bonjour", "B", 0));
  }*/
