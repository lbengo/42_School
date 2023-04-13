/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:13:17 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:29 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La siguiente función añade n carácteres (dstsize - ft_strlen(dst)) de src en
dst y además, retorna el tamaño de src. Asimismo, añade un '\0' al terminar de
copiar dst. Sin embargo, en el caso de que el tamaño que le doi(dstsize) sea 0
o menor que ft_strlen(dst), no se añadirá el '\0'.
---------------------------------------------------------------------------- */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		count;
	size_t	i;
	int		a;

	count = ft_strlen(src) + ft_strlen(dst);
	if (dstsize == 0 || dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	a = ft_strlen(dst);
	while (i < (dstsize - a) - 1 && src[i] != '\0')
	{
		dst[i + a] = src[i];
		i++;
	}
	dst[i + a] = '\0';
	return (count);
}
