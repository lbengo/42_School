/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:07:26 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/16 08:26:47 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La siguiente función busca en un string el último caracter que sea similar
 al caracter buscado, es decir si la frase es "hola que tal" y lo que pretendo
 buscar es "a", el resultado sería "al". En el caso de que busque "i", el
 resulado sería null ya que ese caracter no existe en mi frase */

/* ********************************* EJEMPLO ********************************* */
/*
	- S1 = "hola que tal"
	- set = "a"

	resultado = al.
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}

/* int main(void)
{
	const char s[] = "abbbbbbbbb";
	int c;

	c = 'a' + 1024;
	printf("%s \n", ft_strrchr(s, c));
	printf("%s", strrchr(s, c));
	return (0);
} */
