/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:05 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/04 21:51:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%x - Imprime un número hexadecimal (base 16) en minúsculas.
----------------------------------------------------------------------------- */

/* NOTA:
Para realizar los números negativos se pone unsigned int en lugar de int.
----------------------------------------------------------------------------- */

//if n = "", return (0); En control de errores.

#include "ft_printf.h"

int	ft_putnbr_16(unsigned int n, char *base)
{
	int	len;
	
	len = 1;
	if (n > 15)
	{	
		len += ft_putnbr_16(n/16, base);
		ft_putchar(base[n % 16]);
	}
	else
		ft_putchar(base[n]);
	printf("\n%d", len);
	return (len);
}

/* int main(void)
{
    int n;

    n = -9846;
    ft_putnbr_16_x(n);
	printf("\n%x", -9846);
    return (0);
} */
