/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16_10u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:26:05 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 08:49:20 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%x & %X - Imprimme un número hexadecimal (base 16) en minúsculas y mayúsculas.
%u - Imprime un número decimal (base 10) sin signo.
----------------------------------------------------------------------------- */

/* NOTA:
Se ha situado %u ya que únicamente necesita realizar los números positivos.
Además, se le añade a la función (unsigned int) y no una protección ya que no
se debe gestionar esos números.
----------------------------------------------------------------------------- */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr_16_10u(unsigned int n, char *base)
{
	int	len;
	int	i;

	len = 1;
	i = strlen(base);
	if (i == 16)
	{
		if (n > 15)
		{
			len += ft_putnbr_16_10u(n/i, base);
			ft_putchar(base[n % i]);
		}
		else
			ft_putchar(base[n]);
	}
	if (i == 10)
	{
		if (n > 9)
		{
			len += ft_putnbr_16_10u(n/i, base);
			ft_putchar(base[n % i]);
		}
		else
			ft_putchar(base[n]);
	}
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
