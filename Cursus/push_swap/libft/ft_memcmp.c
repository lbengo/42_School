/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:15:19 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:09:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función memcmp compara la cadena de bytes s1 con la cadena de bytes
s2. Se supone que ambas cadenas tienen una longitud de n bytes. La función
memcmp devuelve cero si las dos cadenas son idénticas, en caso contrario
devuelve la diferencia entre los dos primeros bytes que difieren (tratados
como valores unsigned char, de modo que `\200' es mayor que "0",por ejemplo).
Las cadenas de longitud cero son siempre idénticas. Este comportamiento no es
requerido por C y el código portable debería depender únicamente del signo
del valor devuelto.
---------------------------------------------------------------------------- */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
