/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:17:03 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:00:06 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPCIÓN:
La función atoi convierte un char en un int.
----------------------------------------------------------------------------- */

/* COMO HACERLO:
- Primero sacamos los números uno por uno y los multiplicamos por 10 para que
vaya aumentando progresivamente con el while. Y además, los restamos por '0'
para convertirlos en int.
- Por otro lado, hay que tener en cuenta el símbolo (-) y (+). Lo que queremos
es ... (FALTA)
----------------------------------------------------------------------------- */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				count;
	int				sign;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + str[i] - '0';
		i++;
	}
	return (count * sign);
}
/* int main (void)
{
	const char str[] = "+-546:5";

	printf("%d", ft_atoi(str));
	return (0);
} */
