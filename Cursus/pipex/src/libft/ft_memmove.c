/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:11:49 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:09:35 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función memmove copia len bytes de la cadena src a la cadena dst. Las
funciones no se pueden solapar, por ello si dst es mayor que src hay que
copiarlo de alante hacia atrás. Y, por el contrario, si src es mayor que dst
hay que copiarlo de atrás hacia alante.
---------------------------------------------------------------------------- */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
