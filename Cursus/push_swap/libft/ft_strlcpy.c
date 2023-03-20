/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:59:40 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:11:14 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La siguiente función copia n carácteres (dstsize) de lo que haya en src en dst
y además, retorna el tamaño de src. Asimismo, añade un '\0' al terminar de
copiar dst. Sin embargo, en el caso de que el tamaño que le doi(dstsize) es 0,
no se añadirá el '\0'.
----------------------------------------------------------------------------- */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		count;
	size_t	i;

	count = ft_strlen(src);
	if (dstsize == 0)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

/* int main (void)
{
	const char src[] = "hola";
	char dst[8];
	printf ("dst = %zu y count = %s", ft_strlcpy(dst, src, 3), dst);
	return (0);
} */
