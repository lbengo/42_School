/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:03:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 13:01:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%d & %i - Imprimme un número decimal (base 10).
----------------------------------------------------------------------------- */

#include "ft_printf.h"
#include "libft.h"

int	ft_putnbr_10(int n, char *base)
{
	int	len;
	int	i;

	len = 1;
	i = strlen(base);
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
		len++;
	}
	if (n > (i - 1))
	{
		len += ft_putnbr_10(n/i, base);
		ft_putchar(base[n % i]);
	}
	else
		ft_putchar(base[n]);
	return (len);
}

/* int main(void)
{
	int n;

	n = -9;
	ft_putnbr_10(n, "0123456789");
	printf("\n%i", -9);
	return (0);
} */
