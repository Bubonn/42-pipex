/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:33:33 by jdubilla          #+#    #+#             */
/*   Updated: 2021/12/18 16:17:25 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr_len_bis(unsigned long long n)
{
	unsigned int	nbr;
	int				res;

	nbr = n;
	res = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

int	ft_putnbr_bis(unsigned long long n)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
		ft_putnbr_bis(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	return (ft_nbr_len_bis(n));
}
