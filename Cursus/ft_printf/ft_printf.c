/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:53:39 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 12:09:24 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(char const *format, ...)
{
	unsigned int i;
	unsigned int a;
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
				printf("d");
			else if (format[i+1] == 'i')
				printf("i");
			else if (format[i+1] == 'u')
				printf("u");
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
	return(0);
}

int main (void)
{
	ft_printf("hola chanchito feliz %c %s oi", 'a', "hola");
	//printf("%i", ft_printf("hola chanchito feliz %s oi", 12));
}
