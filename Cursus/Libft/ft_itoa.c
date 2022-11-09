/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:48:43 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 12:03:13 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función itoa pasa un int a un char.
----------------------------------------------------------------------------- */

/* COMO SE HACE:
Primero hay que contar que longitud ocupa el int. Para ello, hay que ir
dividiendo el int entre 10. En el caso de que el último número sea 0, no se
contará el len, ya que no queremos guardar memoria de ese número que no va a
aparecer.

A continuación, hay que tener en cuenta si el número es negativo, por lo que si
es menor que 0, se le añadirá len++, para poner el último carácter de la memoria
y se múltiplia por -1 el int para que se puda ejecutar el siguiente while.

Seguidamente, se realiza la copia del int al str. Para ello, primero se sitúa el
NULL, ya que será lo último, se hacen los 2 whiles para colocar el número, y por
último el signo en el caso de que sea necesario. Se realiza de atrás para alante
(len--), ya que si no los números salen al contrario.

Por último, se protege la función:
	- En el caso de que sea 0, retornará un malloc de 0, por lo que necesitamos
	la función strdup.
	- En el caso de que sea -2147483648, al ser un número tan grande hay que
	imprimirlo directamente.
----------------------------------------------------------------------------- */

/* CUIDADO:
Al hacer el main y probar con int = 0923. El 0 me hacia error por que lo toma
como octal.
----------------------------------------------------------------------------- */

#include "libft.h"

int	ft_intlen(int n)
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

char	*ft_number(int n, unsigned int len, unsigned int sign)
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

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = ft_intlen(n);
	if (n < 0)
	{
		len++;
		n = n * (-1);
		sign = 1;
	}
	return (ft_number(n, len, sign));
}

/* int main(void)
{
	int n;
	char *string;

	n = 0144;
	string = ft_itoa(n);
	printf("mi función = %s", string);
	free(string);
	return (0);
} */
