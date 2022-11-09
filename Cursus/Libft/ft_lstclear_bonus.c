/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:38:50 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 10:50:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo,
utilizando la función ’del’ y free(3). Al final, el puntero a la lista debe
ser NULL.
----------------------------------------------------------------------------- */

/* PARÁMETROS:
- lst: la dirección de un puntero a un nodo.
- del: un puntero a función utilizado para eliminar el contenido de un nodo.
----------------------------------------------------------------------------- */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	while (*lst)
	{
		new = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
	*lst = NULL;
}
