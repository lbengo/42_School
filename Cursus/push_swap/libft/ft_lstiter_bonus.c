/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:54:58 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:50:46 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: un puntero al primer nodo.
- f: un puntero a la función que utilizará cada nodo.
----------------------------------------------------------------------------- */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
