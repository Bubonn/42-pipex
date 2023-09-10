/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:38:54 by jdubilla          #+#    #+#             */
/*   Updated: 2021/12/18 16:16:30 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_hexa_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		return (8);
	while ((nbr / 16) > 0)
	{
		nbr /= 16;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_base(int nbr, char c)
{
	char	*base;

	if (c == 'x' && nbr < 0)
		base = "fedcba9876543210";
	else if (c == 'X' && nbr < 0)
		base = "FEDCBA9876543210";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}

static void	ft_putnbr_hexa_neg(int nbr, char *base, char c)
{
	int		i;
	char	*neg;

	i = 7;
	nbr++;
	nbr *= -1;
	neg = malloc(sizeof(char) * 8 + 1);
	if (!neg)
		return ;
	neg = ft_memset(neg, 102, 8, c);
	while (nbr != 0)
	{
		neg[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	ft_putstr(neg);
	free(neg);
	return ;
}

int	ft_putnbr_hexa(int nbr, char c)
{
	char	*base;
	int		cpy;

	base = ft_base(nbr, c);
	cpy = nbr;
	if (nbr < 0)
	{
		ft_putnbr_hexa_neg(nbr, base, c);
		return (ft_hexa_len(cpy));
	}
	if (nbr > 16 - 1)
	{
		ft_putnbr_hexa(nbr / 16, c);
		nbr %= 16;
	}
	ft_putchar(base[nbr % 16]);
	return (ft_hexa_len(cpy));
}
