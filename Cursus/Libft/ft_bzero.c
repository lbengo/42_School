/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:23:36 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/16 08:24:03 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La función bzero escribe n bytes a cero en la cadena s. Si n es cero, bzero
 no hace nada. */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		n--;
		((char *)s)[n] = 0;
	}
}

/* int main(void)
{
	char s[] = "hola m";
	ft_bzero(s, 4);
	return (0);
} */
