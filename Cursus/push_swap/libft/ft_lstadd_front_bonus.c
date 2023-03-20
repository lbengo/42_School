/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:44:53 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:48:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Añade el nodo ’new’ al principio de la lista ’lst’.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: la dirección de un puntero al primer nodo de una lista.
- new: un puntero al nodo que añadir al principio de la lista.
----------------------------------------------------------------------------- */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = lst[0];
	lst[0] = new;
}
