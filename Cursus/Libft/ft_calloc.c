/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:17:17 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:56:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:

La función calloc guarda un espacio en la memoria (como malloc) y retorna
el string/array guardado en ese espacio, sin embargo, si no se realiza bien,
devuelve null. Asimismo, a diferencia de malloc, todo el espacio que se haya
asignado se pondrá 0.
----------------------------------------------------------------------------- */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = malloc(size * count);
	if (!s)
		return (0);
	ft_memset (s, 0, size * count);
	return (s);
}

/* int main(void)
{
	char s[] = "hola";
	printf("original : %s\n", ft_calloc(5, 4));

	free(s);
	return (0);
} */
