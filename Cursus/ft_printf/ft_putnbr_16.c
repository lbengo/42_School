/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:26:05 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/12 17:34:39 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%x & %X - Imprimme un número hexadecimal (base 16) en minúsculas y mayúsculas.
----------------------------------------------------------------------------- */

#include "ft_printf.h"

int	ft_putnbr_16(unsigned int n, char *base)
{
	int				len;
	unsigned int	i;

	len = 1;
	i = ft_strlen(base);
	if (n > (i - 1))
	{
		len += ft_putnbr_16(n / i, base);
		ft_putchar(base[n % i]);
	}
	else
		ft_putchar(base[n]);
	return (len);
}

/* int main(void)
{
	int n;

	n = -9846;
	ft_putnbr_16(n);
	printf("\n%x", -9846);
	return (0);
} */
