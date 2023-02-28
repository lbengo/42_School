/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:41 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 12:15:34 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_10_u(unsigned int n, char *base)
{
	int				len;
	unsigned int	i;

	len = 1;
	i = ft_strlen(base);
	if (n > (i - 1))
	{
		len += ft_putnbr_10_u(n / i, base);
		ft_putchar(base[n % i]);
	}
	else
		ft_putchar(base[n]);
	return (len);
}
