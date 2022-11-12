/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:53:39 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/12 17:32:17 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list arg, char n)
{
	unsigned int	a;

	a = 0;
	if (n == 'c')
		a = ft_putchar(va_arg(arg, int));
	else if (n == 's')
		a = ft_putstr(va_arg(arg, char *));
	else if (n == 'p')
		a = ft_putpointer(va_arg(arg, long int), BASELOWER);
	else if (n == 'd')
		a = ft_putnbr_10(va_arg(arg, int), BASEDECIMAL);
	else if (n == 'i')
		a = ft_putnbr_10(va_arg(arg, int), BASEDECIMAL);
	else if (n == 'u')
		a = ft_putnbr_10_u(va_arg(arg, unsigned int), BASEDECIMAL);
	else if (n == 'x')
		a = ft_putnbr_16(va_arg(arg, int), BASELOWER);
	else if (n == 'X')
		a = ft_putnbr_16(va_arg(arg, int), BASEUPPER);
	else if (n == '%')
		a = ft_putchar('%');
	return (a);
}

int	ft_printf(char const *format, ...)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	len;
	va_list			arg; // Declara la variable arg
	va_start (arg, format); // Introduce dentro de la variable arg lo que haya en format y ...
	i = 0;
	a = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			a = ft_format(arg, format[i + 1]);
			i++;
		}
		else
			a = ft_putchar(format[i]);
		len = a + len;
		i++;
	}
	va_end(arg); //	Finaliza
	return (len);
}


