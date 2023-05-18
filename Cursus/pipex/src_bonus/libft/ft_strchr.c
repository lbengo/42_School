/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:50:41 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:13 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La siguiente función busca en un string el primer caracter que sea similar
al caracter buscado, es decir si la frase es "hola que tal" y lo que pretendo
buscar es "a", el resultado sería "a que tal". En el caso de que busque "i", el
resulado sería null ya que ese caracter no existe en mi frase.
---------------------------------------------------------------------------- */

/* EJEMPLO:
- S1 = "hola que tal"
- set = "a"

Resultado = a que tal
---------------------------------------------------------------------------- */

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
