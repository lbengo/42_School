/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:50:41 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/16 08:51:52 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La siguiente función busca en un string el primer caracter que sea similar
 al caracter buscado, es decir si la frase es "hola que tal" y lo que pretendo
 buscar es "a", el resultado sería "a que tal". En el caso de que busque "i", el
 resulado sería null ya que ese caracter no existe en mi frase */

/* ********************************* EJEMPLO ********************************* */
/*
	- S1 = "hola que tal"
	- set = "a"

	resultado = a que tal.
 */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*int main(void)
{
	const char s[] = "hola que tal";
	int c;

	c = '\0';
	printf("%s \n", ft_strchr(s, c));
	printf("%s", strchr(s, c));
	return (0);
}*/
