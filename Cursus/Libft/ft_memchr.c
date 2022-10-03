/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:53:38 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/15 17:49:27 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La función memchr localiza la primera ocurrencia de c (convertida a un
unsigned char) en la cadena de s. La función memchr devuelve un puntero al
byte localizado, o NULL si no existe tal byte dentro de n bytes.*/

/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	const char s[] = {0, 1, 2, 3, 4, 5};
	const char s2[] = "bonjourno";

	printf("mio = %s\n", ft_memchr(s, 2, 3));
	printf("maqui = %s", memchr(s, 2, 3));
	return (0);
} */
