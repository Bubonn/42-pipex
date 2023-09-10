/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:45:40 by jdubilla          #+#    #+#             */
/*   Updated: 2021/12/18 16:20:34 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_ptr_len(void *ptr)
{
	unsigned long	nbr;
	int				i;

	nbr = (unsigned long)ptr;
	i = 0;
	while ((nbr / 16) > 0)
	{
		nbr /= 16;
		i++;
	}
	i += 3;
	return (i);
}

static	char	*ft_nbr_to_hexa(char *str, int len, void *addr)
{
	unsigned long	ad;
	char			*base;

	ad = (unsigned long)addr;
	base = "0123456789abcdef";
	str[len] = '\0';
	len--;
	while (len >= 2)
	{
		str[len] = base[ad % 16];
		ad /= 16;
		len--;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

int	ft_print_addr(void *addr)
{
	int		len;
	char	*str;

	if (addr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	len = ft_ptr_len(addr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str = ft_nbr_to_hexa(str, len, addr);
	ft_putstr(str);
	free(str);
	return (len);
}
