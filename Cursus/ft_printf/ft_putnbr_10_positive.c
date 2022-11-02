/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10_positive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:29:24 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/03 00:08:23 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%u - Imprime un número decimal (base 10) sin signo.
----------------------------------------------------------------------------- */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	if (n > 0 && n <= 9)
		len++;
	return (len);
}

static char	*ft_number(unsigned int n, unsigned int len)
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
	return (str);
}

int	ft_putnbr_10_positive(unsigned int n)
{
	unsigned int	len;
	char			*temp;

	len = ft_intlen(n);
	temp = ft_number(n, len);
	ft_putstr(temp);
	free(temp);
	return (0);
}

/* int main(void)
{
	int n;

	n = -144;
	ft_putnbr_10_positive(n);
	printf("\n%u", -144);
	return (0);
} */