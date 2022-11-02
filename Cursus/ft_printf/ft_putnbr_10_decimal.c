/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:46:29 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 23:38:48 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%d - Imprime un número decimal (base 10). Similar al %d, sin embargo %i es un int
y %d es long int.
----------------------------------------------------------------------------- */

#include "ft_printf.h"

static int	ft_intlen(long int n)
{
	unsigned int	len;

	len = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	if (n > 0 && n <= 9)
		len++;
	return (len);
}

static char	*ft_number(long int n, unsigned int len, unsigned int sign)
{
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (n > 9)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	if (n > 0 && n <= 9)
		str[len] = n + '0';
	if (sign == 1)
		str[--len] = '-';
	return (str);
}

int ft_putnbr_10_decimal(long int n)
{
	unsigned int	len;
	unsigned int	sign;
	char			*temp;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (0);
	}
	sign = 0;
	len = ft_intlen(n);
	if (n < 0)
	{
		len++;
		n = n * (-1);
		sign = 1;
	}
	temp = ft_number(n, len, sign);
	ft_putstr(temp);
	free(temp);
	return (0);
}