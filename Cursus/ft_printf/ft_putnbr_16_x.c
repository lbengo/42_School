/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:05:05 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/03 14:17:43 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%x - Imprime un número hexadecimal (base 16) en minúsculas.
----------------------------------------------------------------------------- */

#include "ft_printf.h"

static int	ft_intlen(int n, unsigned int sign)
{
    char            temp;
    char            *base;
    unsigned int    len;
    
    base = "0123456789ABCDEF";
    while (n > 16)
	{
        temp = base[n % 16];
		n = n / 16;
        len++;
	}
    if (sign == 1)
        len++;
    len++;
    return (len);
}

static char	*ft_number(int n, unsigned int sign)
{
    char            *base;
    char            *str;
    char            temp;
    unsigned int    i;
    unsigned int    len;


    base = "0123456789ABCDEF";
    len = ft_intlen(n, sign);
    str = (char *)malloc((len + 1) * sizeof(*str));
    if (!str)
		return (0);
	str[len--] = '\0';
    i = 0;
	while (n > 16)
	{
        str[len--] = base[n % 16];
		n = n / 16;
	}
    str[len] = base[n % 16];
    if (sign == 1)
		str[--len] = '-';
    printf("\n %s", str);
	return (str);
}

int	ft_putnbr_10_i(int n)
{
	char			*temp;
    unsigned int	sign;
    unsigned int    len;

	sign = 0;
	if (n < 0)
	{
		n = n * (-1);
		sign = 1;
	}
    len = ft_intlen(n, sign);
	temp = ft_number(n, sign);
	ft_putstr(temp);
	free(temp);
	return (len);
}

int main(void)
{
    int n;

    n = 15;
    ft_putnbr_10_i(n);
    return (0);
}



/* static int	ft_intlen(int n)
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

void	ft_number(int n)
{
    char    *base;
    char    *str;
    unsigned int i;
    unsigned int j;

    base = "0123456789ABCDEF";
    i = 0;
    len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(*str));
    if (!str)
        return (0);
    str[len--] = '\0';
	while (n > 16)
	{
        str[len--] = base[n % 16];
        printf("%s", str);
		n = n / 16;
        i++;
	}
    str[len] = base[n % 16];
} */

/* int main(void)
{
    int n;

    n = 1523;
    ft_number(n);
    return (0);
} */


/* int	ft_putnbr_10_x(int n)
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
} */