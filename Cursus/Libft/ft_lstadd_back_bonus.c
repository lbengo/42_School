/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:04:00 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:47:42 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Añade el nodo ’new’ al final de la lista ’lst’.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: el puntero al primer nodo de una lista.
- new: el puntero a un nodo que añadir a la lista.
----------------------------------------------------------------------------- */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}
