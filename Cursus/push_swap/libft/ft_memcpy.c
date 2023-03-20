/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:21:29 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:04:32 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función memcpy() copia n bytes del área de memoria src al área de
memoria dst.
----------------------------------------------------------------------------- */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (0);
	while (n > 0)
	{
		n--;
		((char *)dst)[n] = ((char *)src)[n];
	}
	return (dst);
}

/* int main(void)
{
	char dst[] = "";
	char src[] = "";

	printf("%s", ft_memcpy(dst, src, 4));
	return (0);
} */
