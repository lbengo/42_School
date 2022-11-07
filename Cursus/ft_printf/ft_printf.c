/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:53:39 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 13:45:18 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gestionar errores !s

#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	len;
	char			*basex;
	char			*baseX;
	char			*basei;

	va_list arg;	// Declara la variable arg
	va_start (arg, format);	// Introduce dentro de la variable arg lo que haya en format y ...

	i = 0;
	a = 0;
	len = 0;
	basex = "0123456789abcdef";
	baseX = "0123456789ABCDEF";
	basei = "0123456789";
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 'c')
				a = ft_putchar(va_arg(arg, int));
			else if (format[i+1] == 's')
				a = ft_putstr(va_arg(arg, char *));
			else if (format[i+1] == 'p')
				a = ft_putpointer(va_arg(arg, long int), basex);
			else if (format[i+1] == 'd')
				a = ft_putnbr_10(va_arg(arg, int), basei);
			else if (format[i+1] == 'i')
				a = ft_putnbr_10(va_arg(arg, int), basei);
			else if (format[i+1] == 'u')
				a = ft_putnbr_10_u(va_arg(arg, unsigned int), basei);
			else if (format[i+1] == 'x')
				a = ft_putnbr_16(va_arg(arg, int), basex);
			else if (format[i+1] == 'X')
				a = ft_putnbr_16(va_arg(arg, int), baseX);
			else if (format[i+1] == '%')
				a = ft_putchar('%');
			else
				return (20);
			i++;
		}
		else
			a = ft_putchar(format[i]);
		len = a + len;
		i++;
	}

	va_end(arg); //	Finaliza
	return(len);
}
