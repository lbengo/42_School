/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:02:23 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/15 17:51:36 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ******************************* DEFINICION ******************************* */

/* La función memset escribe len bytes de valor c (convertido a un unsigned
char) en la cadena b. */

/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}

/* int main(void)
{
	char b[] = "hola m";
	ft_memset(b, 0, 4);
	return (0);
}
 */
