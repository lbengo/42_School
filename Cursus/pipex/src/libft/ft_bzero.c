/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:23:36 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:08:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:

La función bzero escribe n bytes a cero en la cadena s. Si n es cero, bzero
 no hace nada.
---------------------------------------------------------------------------- */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		n--;
		((char *)s)[n] = 0;
	}
}
