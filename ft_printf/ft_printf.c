/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdubilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 08:41:18 by jdubilla          #+#    #+#             */
/*   Updated: 2021/12/18 16:22:19 by jdubilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_print_arg(const char *str, int i, va_list liste)
{
	int		res;

	res = 0;
	if (str[i] == 'c')
		res = ft_putchar(va_arg(liste, int));
	else if (str[i] == '%')
		res = ft_putchar('%');
	else if (str[i] == 'd' || str[i] == 'i')
		res = ft_putnbr(va_arg(liste, int));
	else if (str[i] == 'x' || str[i] == 'X')
		res = ft_putnbr_hexa(va_arg(liste, int), str[i]);
	else if (str[i] == 'u')
		res = ft_putnbr_bis(va_arg(liste, unsigned long long));
	else if (str[i] == 'p')
		res = ft_print_addr(va_arg(liste, void *));
	else if (str[i] == 's')
		res = ft_putstr(va_arg(liste, char *));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	liste;

	i = 0;
	res = 0;
	if (!str)
		return (-1);
	va_start(liste, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_print_arg(str, i + 1, liste);
			i++;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(liste);
	return (res);
}
