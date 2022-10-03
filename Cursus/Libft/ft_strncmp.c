/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:32:13 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/15 17:56:03 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La siguiente función busca la diferencia que existe entre los dos string
hasta un determinado número, dando como resultado el primer valor diferente.
Por ejemplo, si la primera frase es "Hola que tal" y la segunda "Hola Que al",
el resultado sería "-32". Por otro lado, si le digo que busque 3 carácteres,
nunca encontrará la diferencia, devolviendome el resultado de null. Asimismo,
obtendremos este resultado si no existiese ninguna diferencia entre ambas */

/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	size_t			a;

	i = 0;
	a = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (a < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
		a++;
	}
	return (0);
}

/* int main(void)
{
	const char s1[] = "\200";
	const char s2[] = "\0";

	printf("%d\n", ft_strncmp(s1, s2, 6));
	printf("%d\n", strncmp(s1, s2, 6));
	return (0);
} */
