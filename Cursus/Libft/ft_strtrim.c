/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:54:10 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:15:48 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función strtrim elimina los primeros y últimos carácteres de la string s1
si contiene los mismos caracteres de set.
----------------------------------------------------------------------------- */

/* COMO SE HACE:
Se usa strchr para seleccionar el primer y último valor igual en la s1.
Asimismo, se incluye (i < j) para que si hay un s1 = "   " y set = " ", no
produzca error.

Por último, se retorna substr para que retorne s1 desde los puntos que me han
dado strchr. Se incluye en el último valor de esta función (j - i + 1) para
que te de el valor total del string final, y el más uno ya que hay que añadir
un caracter más.
----------------------------------------------------------------------------- */

/* EJEMPLO:
- S1 = "hola que tal"
- set = "hel"

Resultado = ola que ta
----------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != 0 && i < j)
		i++;
	while (ft_strchr(set, s1[j]) != 0 && i < j)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}

/* int main(void)
{
	char const s1[] = "       ";
	char const set[] = "  ";

	printf("mi funcion:%s\n", ft_strtrim(s1, set));
	return (0);
}
 */
