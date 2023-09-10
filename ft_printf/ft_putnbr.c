/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:33:33 by jdubilla          #+#    #+#             */
/*   Updated: 2021/12/18 16:15:56 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len(int nbr)
{
	int	res;

	res = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		res++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

int	ft_putnbr(int n)
{
	int	cpy;

	cpy = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbr_len(cpy));
}
