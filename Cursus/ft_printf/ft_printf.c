/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:53:39 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 23:58:58 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
	unsigned int i;
	va_list arg;	// Declara la variable arg
	va_start (arg, format);	// Introduce dentro de la variable arg lo que haya en format y ...

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 'c')
				ft_putchar(va_arg(arg, int));
			else if (format[i+1] == 's')
				ft_putstr(va_arg(arg, char *));
			else if (format[i+1] == 'p')
				printf("p");
			else if (format[i+1] == 'd')
				ft_putnbr_10_decimal(va_arg(arg, long int));
			else if (format[i+1] == 'i')
				ft_putnbr_10_integer(va_arg(arg, int));
			else if (format[i+1] == 'u')
				ft_putnbr_10_positive(va_arg(arg, unsigned int));
			else if (format[i+1] == 'x')
				printf("x");
			else if (format[i+1] == 'X')
				printf("X");
			else if (format[i+1] == '%')
				printf("%%");
			else
				return (20);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}

	va_end(arg); //	Finaliza
	return(1);
}
