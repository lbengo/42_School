/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:53:39 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/04 21:51:42 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	len;
	char			*base;
	
	va_list arg;	// Declara la variable arg
	va_start (arg, format);	// Introduce dentro de la variable arg lo que haya en format y ...

	i = 0;
	a = 0;
	len = 0;
	base = "0123456789abcdef";
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 'c')
				a = ft_putchar(va_arg(arg, int));
			else if (format[i+1] == 's')
				a = ft_putstr(va_arg(arg, char *));
			else if (format[i+1] == 'p')
				printf("p");
			else if (format[i+1] == 'd')
				a = ft_putnbr_10_d(va_arg(arg, int));
			else if (format[i+1] == 'i')
				a = ft_putnbr_10_i(va_arg(arg, int));
			else if (format[i+1] == 'u')
				a = ft_putnbr_10_u(va_arg(arg, unsigned int));
			else if (format[i+1] == 'x')
				a = ft_putnbr_16(va_arg(arg, int), base);
			else if (format[i+1] == 'X')
				printf("X");
			else if (format[i+1] == '%')
				printf("%%");
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
