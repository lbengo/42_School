/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:46:29 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/03 11:53:45 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%d - Imprime un número decimal (base 10). Similar al %d, sin embargo %i es un int
y %d es long int.
----------------------------------------------------------------------------- */

#include "ft_printf.h"

static int	ft_intlen(int n)
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
	if (n >= 0 && n <= 9)
		len++;
	return (len);
}

static char	*ft_number(int n, unsigned int len, unsigned int sign)
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
	if (n >= 0 && n <= 9)
		str[len] = n + '0';
	if (sign == 1)
		str[--len] = '-';
	return (str);
}

int ft_putnbr_10_d(int n)
{
	unsigned int	len;
	unsigned int	sign;
	char			*temp;

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
	return (len);
}

/* int main(void)
{
	int n;

	n = -11;
	ft_putnbr_10_d(n);
	return (0);
} */
