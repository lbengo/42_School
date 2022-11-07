/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:41 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 13:44:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
%u - Imprime un número decimal (base 10) sin signo.
----------------------------------------------------------------------------- */

/* NOTA:
Se ha extraido %u ya que únicamente necesita realizar los números positivos,
por lo que se le añade a la función (unsigned int) y no una protección ya que
no se debe gestionar dichos números.
----------------------------------------------------------------------------- */

#include "libft.h"
#include "ft_printf.h"

int	ft_putnbr_10_u(unsigned int n, char *base)
{
	int	len;
	int	i;

	len = 1;
	i = strlen(base);
	if (n > 9)
	{
		len += ft_putnbr_10_u(n / i, base);
		ft_putchar(base[n % i]);
	}
	else
		ft_putchar(base[n]);
	return (len);
}
