/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:30:07 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 09:30:26 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_putpointer (unsigned long long int n, char *base)
{
	unsigned int	len;
	int				i;

	len = 1;
	i = strlen(base);
	if (n > 15)
	{
		len += ft_putpointer(n/i, base);
		ft_putchar(base[n % i]);
	}
	else
	{
		ft_putstr("0x");
		len = len + 2;
		ft_putchar(base[n]);
	}

	return(len);
}

/* int main (void)
{
    long int *pointer;
	char *base;
	int	a;
	int b;

	pointer = 15;
	base = "0123456789abcdef";
    a = ft_putpointer(pointer, base);
	b = printf("\n%p", pointer);
	printf("\n %i \n %i", a, b);
} */
